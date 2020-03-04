// c++ refactor of python game of life
// rules from 1979 byte mag
#include<iostream>
#include<vector> 
//#include<unistd.h>
#include <chrono> //newer c++ use 
#include <thread> // this for sleep 
using namespace std;

// global 2d array so all can functions can use it
//https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
vector<vector<int> > oldworld
 		   {
 		   	{0,0,0,0,0,0,0,0,0,0},   
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,1,1,1,0,0,0,0},
            {0,0,0,0,0,1,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}
        };

int cols = 10; //x
int rows = 10; //y

void clrtrm(){  //https://stackoverflow.com/questions/17335816/clear-screen-using-c
	cout << "\033[2J\033[1;1H";
}

void showWorld(){

	for(int y =0; y < rows; y++){
		string line ="";
		for(int x=0;x< cols; x++){

            if (oldworld[y][x] == 0){
                line = line+".";
            }
            else{
                line=line+"*";
            }
		}
		cout<< line <<"\n";
	}

}

int countNeighbors(int y, int x){
    //global oldworld, cols, rows
    int sum = 0;
    for(int j=-1; j <2; j++){

        for (int i = -1; i < 2; i++){
            int row = (y + j + rows) % rows;
            int col = (x + i + cols) % cols;  //using modulo to count over 
             
            sum += oldworld[row][col];
        }
    }

    sum -= oldworld[y][x];
    return sum;
}

void nextGen(){
    // global oldworld rows cols
    // Create a vector containing rows (https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/)
    //vectors of size cols.  
    vector<vector<int> > newworld( rows , vector<int> (cols, 0));
     
    for (int y = 0; y<rows;y++){
        for(int x =0; x<cols;x++){
            
            int nei = countNeighbors(y,x); //make sure you get your x's and y's straight
            if (nei == 3){
                newworld[y][x] = 1;   //live or dead if three neighbors next gen will be live or 1
            }
                
            else if (nei == 2){    //live or dead if two neighbors the next gen will be the same as this one
                newworld[y][x] = oldworld[y][x];
             }   
            
            else{     //else live or dead any other number of neighbors next gen is dead or 0
                
                newworld[y][x] = 0;
            }
    	}
    }            
    oldworld = newworld; // you can just copy vectors https://stackoverflow.com/questions/25026958/what-is-the-best-way-to-copy-a-2d-vector
}

int main()
{
	showWorld();
	for(int g =0; g<100;g++){
		clrtrm();
		nextGen();
		showWorld();
		cout<<"Generation "<<g<<"\n";
		//sleep(1);
		this_thread::sleep_for(chrono::milliseconds(200)); //https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
	}

}