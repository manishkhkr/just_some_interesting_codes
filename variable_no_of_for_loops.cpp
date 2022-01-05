/* Problem : how can we write a program that does not have a fixed number of loops.
But instead run as many loops as required. Breaking free of i,j,k

this program uses an array to achieve above and user can provide no of loops at execution time.
Problem proposed by Braja Bandhu Patikar

*/

#include<iostream>
#include<malloc.h>

using namespace std;

void just_print_the_loop_info();

int total_loops = 0;
int * array_ptr = NULL;

int main()
{

    int each_loop_cnt = 0;
    int counter = 0;

    cout<<"Enter how many loops you want to run : ";
    cin >>total_loops;

    cout<<"How many time each loop should run : ";
    cin>> each_loop_cnt;

    array_ptr = (int *)malloc((total_loops+1)*sizeof(int));
    int i=0,j=0;

    //  init all positions to 0
    for(i=0;i<total_loops+1;i++)
    {
        array_ptr[i] = 0;
    }

    int curr_pos = 0;
    while(curr_pos < total_loops)
    {

        curr_pos = 0;
        while(array_ptr[0] < each_loop_cnt)
        {
            // do something here
            just_print_the_loop_info();  //  uncomment to visualize
            counter++;
            array_ptr[0]++;
        }
        array_ptr[curr_pos] = 0;
        curr_pos++;

        //  increase in upper levels till ?

        while(array_ptr[curr_pos] == each_loop_cnt-1)
        {
            array_ptr[curr_pos] = 0;
            curr_pos++;

        }
        array_ptr[curr_pos]++;
    }

    cout<<"counter : " << counter <<endl;

    return 0;

}

void just_print_the_loop_info()
{
    //  this is going to increase the runtime dramatically
    int i = 0;
    for(i=total_loops-1;i>=0;i--)
    {
        cout <<array_ptr[i] << " ";
    }
    cout<<endl;
}
