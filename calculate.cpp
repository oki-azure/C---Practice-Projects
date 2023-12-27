#include <cstdio>
#include <string>

int main(int argc, char** argv) {
    std::string argument;

    size_t index{1};

    while (index < argc) {
        argument.append(argv[index]);
        index++;
    }

    std::string arg1, arg2;

    using namespace std::string_literals;

    auto operators = "+-*/%"s;

    for (char op : operators) {
        size_t indx = argument.find(op);

        if (indx != std::string::npos) {
            auto itr = argument.begin();

            auto signItr = itr + indx;

            arg1.append(itr, signItr);

            arg2.append((signItr+1), argument.end());

            const auto arg1L = std::stoul(arg1);

            const auto arg2L = std::stoul(arg2);

            switch (op) {
                case '+': {
                    printf("%s + %s = %lu\n", arg1.c_str(), arg2.c_str(), (arg1L + arg2L));
                    break;
                }

                case '-': {
                    printf("%s - %s = %lu\n", arg1.c_str(), arg2.c_str(), (arg1L - arg2L));
                    break;
                }

                case '*': {
                    printf("%s * %s = %lu\n", arg1.c_str(), arg2.c_str(), (arg1L * arg2L));
                    break;
                }

                case '/': {
                    printf("%s / %s = %.1f\n", arg1.c_str(), arg2.c_str(), static_cast<double>( (arg1L / arg2L) ) );
                    break;
                }

                case '%': {
                    printf("%s mod %s = %.1f\n", arg1.c_str(), arg2.c_str(), static_cast<double>( (arg1L % arg2L) ) );
                    break;
                }
                    
                default: printf("Invalid argument");
                   
            }
        }
    }
}