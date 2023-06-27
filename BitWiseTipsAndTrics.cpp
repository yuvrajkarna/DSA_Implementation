#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
    //To Check whether the given number n is odd or even
    if(number & 1){
        cout<<"Odd";
    }else{
        cout<<"Even";
    }
    */

    /* 
    //To Check that any given number is power of 2 or not 
    power of two numbers are like=>
    x=32 bin(x)= 000000100000   bin(x-1)=000000011111
    x=8  bin(x)=000000001000   bin(x-1)=000000000111
    so if we will take AND then it will come zero 
    Edge Case:it will not work for zero(0) so we have to handle it by ourself
    if(x && x & (x-1) != 0){
        cout<< "Not a Power Of Two ";
    } else {
        cout << "Power Of
    }
    */

   /*
   //How to find any power of 2 i.e pow(2,k)
    int pow(int k){
        return (1<<k);//pow(2,k)
    }
   */

    /*
    //Check if kth bit is set or not
    bool isKthBitSet(int n,int k){
        return (n & (1<<k));
    }
    */

    /*
    //Toggle kth bit 
    //it means at kth bit it will reverse that bit i.e 0 to 1 and 1 to 0
    bool toggleKthBit(int n,int k){
        return (n ^ (1<<k));
    }
    */

    /*
    //set kth bit of any number n
    bool isKthBitSet(int n,int k){
        return (n | (1<<k));
    }
    */


    /*
    //Unset kth bit of any number n
    bool isKthBitSet(int n,int k){
        return (n & ~(1<<k));
    }
    */

    /*
    //multiply or divide a number x by 2^k
    multiplication: (x<<k)
    Division: (x>>k)
    */

    /*
    //take modulo of any number x by 2^k
    remainder will be =(x & (2^k-1))
                      =(x & ((1<<k)-1))
    */

    /*
    //Swap two number without using two number i.e x AND y
    x=x^y;
    y=x^y;
    x=x^y;
    */

    /*
    Property:
        no. of set bits in any number A = X
        no. of set bits in any number B = Y
        no of set bits in (A^B) i.e A XOR B = Z

        then z 
            is even if (X+Y) is even
            is odd if (X+Y) is odd

    EXPLANATION:
    This is because of XOR Property
    i.e if it gets 1 at any kth position in both number A and B
    then total number of set bits gets reduced by two i.e (X+Y -2)
    And lets say if there is t number of position where 1 are at same position
    then total number of set bits will be (X+Y - 2*t);
    2*t is always even so X+y will be diciding factor 

    A=(1100110001)
    b=(0100110010)
    here t=3
    */

    /*
    Techniques:
    if(X==A){
        X=B;
    }
    else if(X==B){
        X=A;
    }
    this can be done as => X=A^B^X
    */

    /*
    A+B=(A ^ B) + 2(A & B)
    A+B=(A | B) + (A & B)
    */

    /*
    x=int
    Number_of_set_bits_in_x=__builtin_popcount(x);
    x=long long
    Number_of_set_bits_in_x=__builtin_popcountll(x);

    */

    /*
    */

    return 0;
}