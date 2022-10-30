//Jazmin Joy M. Fullante BSCpE 4A
//CPE 411 Embedded System
//Activity 5 - Memory, Memory Testing and Peripheral
//C++ implementation of Checksum
#include<iostream>
#include<string.h>

using namespace std;

/*
 * Main function of the program
 * Ask for sent and received binary data from the user
 * The data inputs will be used to get the Checksum
 */
int main()
{
    char a[50], b[50];
    char sum[50], complement[50];
    int i;

    cout<<"Enter the sent binary data : ";
    cin>>a;
    cout<<"Enter the received binary data : ";
    cin>>b;

    if (strlen(a) == strlen(b)) {
        char carry = '0';
        int length = strlen(a);

        /*
         * In order to get the sum there are 6 cases:
         * a. If both bits are 0 and carry is 0, sum = 0 and carry = 0
         * b. If both bits are 0 and carry is 1, sum = 1 and carry = 0
         * c. If both bits are 1 and carry is 0, sum = 0 and carry = 1
         * d. If both bits are 1 and carry is 1, sum = 1 and carry = 1
         * e. If either bit is 1 and carry is 0, sum = 1 and carry = 0
         * f. If either bit is 1 and carry is 1, sum = 0 and carry = 1
         */

        for (i = length-1; i >= 0; i--) {
            if (a[i] == '0' && b[i] == '0' && carry == '0') {
                sum[i] = '0';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '0' && carry == '1') {
                sum[i] = '1';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '0') {
                sum[i] = '1';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '1') {
                sum[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '0') {
                sum[i] = '1';
                carry = '0';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '1') {
                sum[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '0') {
                sum[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '1') {
                sum[i] = '1';
                carry = '1';
            }
            else
                break;
        }

        /*
         * The result is the Sum
         * When the sum is done 1's complement of it is taken by reversing 1's to 0's and vice versa
         */
        cout<<"\nSum = "<<carry<<sum;

        for (i = 0; i < length; i++) {
            if ( sum [i] == '0')
                complement[i] = '1';
            else
                complement[i] = '0';
        }

        /*
         * The resulting 1's complement is the Checksum
         * If checksum is 0 it means no error in data received
         * Else there exist some error in the received data
         *
         */
        if(carry == '1')
            carry = '0';
        else
            carry = '1';

            cout<<"\nChecksum = "<<carry<<complement;
        }
        else
            cout<<"\nError";

            return 0;
}
