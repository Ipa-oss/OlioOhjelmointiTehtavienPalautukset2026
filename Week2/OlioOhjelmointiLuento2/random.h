#ifndef RANDOM_H
#define RANDOM_H

class Random // Class has to have first letter uppercase and constructor needs to be the same name as class.
{
public:
    Random(); // Constructor. Runs on object(olio) creation.
    void setSeed(long long);
    long long getSeed();
    long long rand();
private:
    long long a;
    long long c;
    long long Xn;
    long long mod;
};

#endif // RANDOM_H
