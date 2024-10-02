#include <string>
#include <iostream>


class ShiftRegister {
public:
// Constructor to create LFSR with the given initial seed
    ShiftRegister(std::string seed);
//get seed
    std::string getSeed();
// Simulate one step and return the new bit as 0 or 1
    int step();
// Simulate k steps and return a k-bit integer
    int generate(int k);

    friend std::ostream& operator<<(std::ostream& outStream, const FibLFSR& lfsr);
private:
    std::string initSeed;
};

