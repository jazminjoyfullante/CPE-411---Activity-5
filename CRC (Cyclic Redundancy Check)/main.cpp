//Jazmin Joy M. Fullante BSCpE 4A
//CPE 411 Embedded System
//Activity 5 - Memory, Memory Testing and Peripheral
//C++ implementation of CRC (Cyclic Redundancy Check)
#include<iostream>

using namespace std;
void division(int temp[],int gen[],int a, int b) {
    for (int i = 0; i < a; i++) {
        if (gen[0] == temp[i]) {
            for (int j = 0, k = i; j < b + 1; j++, k++)
                if (!(temp[k]^gen[j]))
                    temp[k] = 0;
                else
                    temp[k] = 1;
        }
    }
}

/*
 * Main function of the program
 * At the Sender's End
 * Ask for number of message and generator bits from the user
 * Ask for message and generator data from the user
 * The data inputs will be used to get the Cyclic Redundancy Check
 */
int main() {
    int a, b, message[50], gen[50], temp[50];

    cout<<"SENDER";
    cout<<"Enter the number of message bits: ";
    cin>>a;
    cout<<"Enter the number of generator bits: ";
    cin>>b;
    cout<<"Enter the message data: ";

    for (int i = 0; i < a; i++)
        cin>>message[i];

    cout<<"Enter the generator data: ";

    for (int i = 0; i < b; i++)
        cin>>gen[i];
        b--;

    /*
     * Calculate the CRC
     * A polynomial divisor of length n+1 to partition the source number
     * Disposing of the quotient and utilizing the remainder as the check whole for that message.
     */
    for (int i = 0; i < b; i++)
        message[a + i] = 0;

    for (int i = 0; i < a + b; i++)
        temp[i] = message[i];
        division(temp, gen, a, b);
        cout<<"CRC : ";

    for (int i = 0; i < b; i++) {
        cout<<temp[a + i]<<" ";
        message[a + i] = temp[a + i];
    }

    cout<<endl<<"Transmitted Message = ";
    for (int i = 0; i < a + b; i++)
        cout<<message[i]<<" ";

    /*
     * At the Receiver's End
     * Ask for the received message data
     * If error is detected in received message will return
     * Else no error in received message
     */
    cout<<endl<<endl<<"RECEIVER"<<endl;
    cout<<"Enter the received message data: ";
    for (int i = 0; i < a + b; i++)
        cin>>message[i];

    for (int i = 0; i < a + b; i++)
        temp[i] = message[i];
        division(temp, gen, a, b);

    for (int i = 0; i < b; i++) {
        if (temp[a + i]) {
            cout<<"Error detected in received message.";
            return 0;
        }
    }

    cout<<"No error in received Message";
    cout<<"Received Message: ";
    for (int i = 0; i < a; i++)
        cout<<message[i]<<" ";

    return 0;
}
