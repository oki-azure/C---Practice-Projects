#include <cstdint>
#include <cstdio>
#include <functional>
#include <stdexcept>
#include <exception>

/***************************************************************************************************************************************  
10-1
Your car company has completed work on a service that detects speed limits based on signage it observes on the side of the road. 

The speed-limit-detection team will publish objects of the following type to the event bus periodically:
struct SpeedLimitDetected {
    unsigned short speed_mps;
}

The service bus has been extended to incorporate this new type:
#include <functional>
--snip--
using SpeedUpdateCallback = std::function<void(const SpeedUpdate&)>;
using CarDetectedCallback = std::function<void(const CarDetected&)>;
using SpeedLimitCallback = std::function<void(const SpeedLimitDetected&)>;
struct IServiceBus {
    virtual ~IServiceBus() = default;
    virtual void publish(const BrakeCommand&) = 0;
    virtual void subscribe(SpeedUpdateCallback) = 0;
    virtual void subscribe(CarDetectedCallback) = 0;
    virtual void subscribe(SpeedLimitCallback) = 0;
};

Update the service with the new interface and make sure the tests still pass. 


10-2
Add a private field for the last known speed limit. Implement a getter method for this field.


10-3
The product owner wants you to initialize the last known speed limit to 39 meters per second. 

Implement a unit test that checks a newly constructed AutoBrake that has a last known speed limit of 39.


10-4
Make unit tests pass.


10-5
Implement a unit test where you publish three different SpeedLimitDetected objects using the same callback technique you used for SpeedUpdate and 
CarDetected. 

After invoking each of the callbacks, check the last known speed limit on the AutoBrake object to ensure it matches.


10-6
Make all unit tests pass.


10-7
Implement a unit test where the last known speed limit is 35 meters per second, and you’re traveling at 34 meters per second. 

Ensure that no BrakeCommand is published by AutoBrake.


10-8
Make all unit tests pass.
***************************************************************************************************************************************/

struct SpeedUpdate { double velocity_mps; };

struct CarDetected {
	double distance_m;
	double velocity_mps;
};

struct BrakeCommand { double time_to_collision_s; };
struct SpeedLimitDetected { unsigned short speed_mps; };

using SpeedUpdateCallback = std::function< void(const SpeedUpdate&) >;
using CarDetectedCallback = std::function< void(const CarDetected&) >;
using SpeedLimitCallback = std::function< void(const SpeedLimitDetected&) >;

struct IServiceBus {
	virtual ~IServiceBus() = default;
	virtual void publish(const BrakeCommand&) = 0;
	virtual void subscribe(const SpeedUpdateCallback&) = 0;
	virtual void subscribe(const CarDetectedCallback&) = 0;
	virtual void subscribe(const SpeedLimitCallback&) = 0;
};

struct MockServiceBus : IServiceBus {
	void publish(const BrakeCommand& cmd) override {
		commands_published++;
		last_command = cmd;
	}

	void subscribe(const SpeedUpdateCallback& callback) override { speed_update_callback = callback; }
	void subscribe(const CarDetectedCallback& callback) override { car_detected_callback = callback; }
	void subscribe(const SpeedLimitCallback& callback) override { speed_limit_callback = callback; }

	BrakeCommand last_command{};
	int commands_published{};
	SpeedUpdateCallback speed_update_callback{};
	CarDetectedCallback car_detected_callback{};
	SpeedLimitCallback speed_limit_callback{};
};

struct AutoBrake {
    AutoBrake(IServiceBus& bus) : speed_mps{}, collision_threshold_s{5}, last_known_speed_limit_mps{39} {
        bus.subscribe(
            [this, &bus](const SpeedUpdate& update) {
                speed_mps = update.velocity_mps;
                if (last_known_speed_limit_mps < speed_mps) bus.publish(BrakeCommand{5}); 
            }
        ); 

        bus.subscribe(
            [this, &bus](const CarDetected& cd) {
                const auto relative_velocity_mps = speed_mps - cd.velocity_mps; 
                const auto time_to_collision_s = cd.distance_m / relative_velocity_mps; 
                if ((time_to_collision_s > 0) && (time_to_collision_s <= collision_threshold_s)) bus.publish(BrakeCommand{time_to_collision_s}); 
            }
        );

        bus.subscribe(
            [this](const SpeedLimitDetected& sld) { last_known_speed_limit_mps = sld.speed_mps; }
        );
    } 

    void set_collision_threshold_s(double x) {
        if (x < 1) throw std::runtime_error{"Collision less than 1"}; 
        collision_threshold_s = x; 
    }

    double get_collision_threshold_s() const { return collision_threshold_s; }
    double get_speed_mps() const { return speed_mps; }
    double get_last_known_speed_limit() const { return last_known_speed_limit_mps; }

    private:
        double collision_threshold_s; 
        double speed_mps;  
        double last_known_speed_limit_mps; 
};

constexpr void assert_that(bool statement, const char* message) { if (!statement) throw std::runtime_error{message}; }

void run_test(void(*unit_test)(), const char* name) {
    try {
        unit_test(); 
        printf("[+] Test %s successful\n", name); 
    }

    catch (const std::exception& e) { printf("[-] Test failure in %s. %s.\n", name, e.what()); }
}

void initial_speed_is_zero() {
    MockServiceBus bus; 
    AutoBrake auto_brake{bus}; 
    assert_that((auto_brake.get_speed_mps() == 0L), "speed not equal to 0"); 
}

void initial_sensitivity_is_five() {
    MockServiceBus bus{}; 
    AutoBrake auto_brake = bus; 
    assert_that((auto_brake.get_collision_threshold_s() == 5), "sensitivity is not 5"); 
}

void sensitivity_greater_than_1() {
    MockServiceBus bus{}; 
    AutoBrake auto_brake = bus; 

    try { auto_brake.set_collision_threshold_s(0.5L); }
    catch (const std::exception&) { return; }

    assert_that(false, "no exception thrown"); 
}

void speed_is_saved() {
    MockServiceBus bus{}; 
    AutoBrake auto_brake{bus}; 
    bus.speed_update_callback( SpeedUpdate{100L} ); 
    assert_that( (100L == auto_brake.get_speed_mps()), "speed not saved to 100" ); 
    bus.speed_update_callback( SpeedUpdate{50L} );
    assert_that( (50L == auto_brake.get_speed_mps()), "speed not saved to 50" ); 
    bus.speed_update_callback( SpeedUpdate{0L} );
    assert_that( (0L == auto_brake.get_speed_mps()), "speed not saved to 0" ); 
}

void alert_when_imminent() {
    MockServiceBus bus{}; 
    AutoBrake auto_brake{bus}; 
    auto_brake.set_collision_threshold_s(10L); 
    bus.speed_limit_callback( SpeedLimitDetected{110L} );
    bus.speed_update_callback( SpeedUpdate{100L} ); 
    bus.car_detected_callback( CarDetected{100L, 0L} ); 
    assert_that( (bus.commands_published == 1), "no brake commands published" ); 
    assert_that( (bus.last_command.time_to_collision_s == 1L), "time to collision not computed correctly" );
} 

void no_alert_when_not_imminent() {
    MockServiceBus bus{}; 
    AutoBrake auto_brake{bus}; 
    auto_brake.set_collision_threshold_s(2L); 
    bus.speed_limit_callback( SpeedLimitDetected{110L} );
    bus.speed_update_callback( SpeedUpdate{100L} ); 
    bus.car_detected_callback( CarDetected{1000L, 50L} ); 
    assert_that( (bus.commands_published == 0), "brake commands were published" ); 
}

void initial_last_known_limit_speed_is_39() {
    MockServiceBus bus; 
    AutoBrake auto_brake{bus}; 
    assert_that( 39 == auto_brake.get_last_known_speed_limit(), "speed limit is not 39" ); 
}

void match_last_known_speed_limit() {
	MockServiceBus bus{};
	AutoBrake auto_brake{bus};
	bus.speed_limit_callback( SpeedLimitDetected{100} );
	assert_that( 100 == auto_brake.get_last_known_speed_limit(), "100 was not logged" );
	bus.speed_limit_callback( SpeedLimitDetected{150} );
	assert_that( 150 == auto_brake.get_last_known_speed_limit(), "150 was not logged" );
	bus.speed_limit_callback( SpeedLimitDetected{200} );
	assert_that( 200 == auto_brake.get_last_known_speed_limit(), "200 was not logged" );
}

void no_brake_when_less_than_speed_limit() {     
    MockServiceBus bus{};
	AutoBrake auto_brake{bus};

    // set current speed limit to 35 mps
    bus.speed_limit_callback(SpeedLimitDetected{35L});

    // Car is travelling at 34 mps, no brake command should be published
    bus.speed_update_callback(SpeedUpdate{34L});

    //assert_that((40L == auto_brake.get_speed_mps()), "speed not saved"); 

	assert_that(bus.commands_published == 0, "speed limit not exceeded");
}

int main() {
    run_test(initial_speed_is_zero, "initial speed is 0"); 
    run_test(initial_sensitivity_is_five, "initial sensitivity is 5"); 
    run_test(sensitivity_greater_than_1, "sensitivity greater than 1"); 
    run_test(speed_is_saved, "speed is saved"); 
    run_test(alert_when_imminent, "alert when imminent");
    run_test(no_alert_when_not_imminent, "no alert when not imminent");
    run_test(initial_last_known_limit_speed_is_39, "initial last known speed limit should be 39"); 
    run_test(match_last_known_speed_limit, "last known speed limit is matched"); 
    run_test(no_brake_when_less_than_speed_limit, "no brake when under speed limit");  
}