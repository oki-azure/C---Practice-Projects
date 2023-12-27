#include <cstdio>
#include <cstdint>
#include <string>
#include <map>
#include <unordered_map>
#include <string_view>

// A program that displays a histogram for the distribution of characters in CLI arguments
 
constexpr char pos_A{ 65 }, pos_Z{ 90 }, pos_a{ 97 }, pos_z{ 122 };

constexpr bool within_AZ(char x) { return pos_A <= x && pos_Z >= x; }

constexpr bool within_az(char x) { return pos_a <= x && pos_z >= x; }

struct AlphaHistogram {
	void ingest(const std::string_view& input);

	void print() const;

    private:
	    std::unordered_map<char, int> counts;
};

void AlphaHistogram::ingest(const std::string_view& input) {
	for (char c : input) {
		if (within_AZ(c)) counts[c]++;
		
		else counts[c - (pos_a - pos_A)]++;
		
	}
}

void AlphaHistogram::print() const {
    for (auto index{pos_A}; index <= pos_Z; index++) {
        printf("%c: ",index);

        if (counts.find(index) != counts.end()) {
            auto n_asterisks = counts.at(index);

            while (n_asterisks--) printf("*");   
        }

        printf("\n");
    }
}

int main(int argc, char** argv) {
    AlphaHistogram hist;

    for (size_t i{1}; i < argc; i++) hist.ingest(argv[i]);

    hist.print();
}