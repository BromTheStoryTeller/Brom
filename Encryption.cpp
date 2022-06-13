#include <bits/stdc++.h>
#include <cmath>
using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    //Using the size of the input string in order 
    //to find the floor and the ceiling
    int strSize = s.size();
    float squRoot = sqrt(strSize);
    int floorNum = floor(squRoot);
    int ceilingNum = ceil(squRoot);

    //Checking the edge case that the product of the 
    //floor and ceiling is less than the product
    if ( floorNum *ceilingNum < strSize)    {
        //In the event of an edge case increase the floor 
        //to the same value of the ceiling
        floorNum = ceilingNum;
    }

    //Create the matrix with the paramerts determined above
    char mat [floorNum][ceilingNum];

    //Traverse the matrix and assign the one character of the 
    //string to an element of the the matrix by row then column
    int counter = 0;
    for (int x=0; x<floorNum; x++) {
        for (int y=0; y<ceilingNum; y++) {
            //Checking to see if all the character of the 
            //string has been assigned to the matrix
            if(counter >= strSize)  {
                    //if the check is true then place a "*" as a 
                    //marker that this space should be empty
                    mat[x][y] = NULL;
                }   else {
                    mat[x][y] = s[counter];
                    counter = counter +1;
                }
        }
    }

    string retString = "";
    for (int y=0; y<ceilingNum; y++) {
        for (int x=0; x<floorNum; x++) {
            //if the element is not marked as a empty space
            //put it on the return String
            if (mat[x][y] != NULL)   {
                retString = retString + mat[x][y];
            }
        }
        retString = retString + " ";
    }
    return retString;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
