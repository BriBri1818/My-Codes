#include <stdio.h>
void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB);
int checkNext(int, int, int, int, int firstArr[], int secondArr[]);

void longestSequence(int a[], int sizeA);

int main()
{
    int a[] = {1, 2, 3, 4, 1000, 90, 100, 110, 200, 202};
    int b[] = {1, 2, 3, 4, 1000, 90, 100, 110, 200, 202};
    longestMutualSequence(a, b, 10, 10);
    return 0;
}

void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB)
{
    int sequenceSize, finalLength = 0, start;

    for (int i = 0; i < sizeA; i++) //will check every index in the first array 
    {
        for(int j = 0; j < sizeB; j++) //will check every index in the second array
        {
            if(firstArr[i] == secondArr[j]) //if an index in the first array is equal to the same one in the second array
                sequenceSize = checkNext(i, j, sizeA, sizeB, firstArr, secondArr); //calls on function to see how long the sequence is
            
            else 
            {
                for(int k = 1; k < (sizeB - 1) && k < (sizeB - 1); k++) //will see if an a value in the first array appears anywhere in the second
                {
                    int nextJ = j + k;
                    if(firstArr[i] == secondArr[nextJ]) //when a value in the first array is equal to a value in the second
                        sequenceSize = checkNext(i, nextJ, sizeA, sizeB, firstArr, secondArr); // calls on function to see how long the sequence is
                        
                    else
                        sequenceSize = 0; //means there is no sequence
                }
            }
            
            if(sequenceSize > finalLength) //will make sure the longest sequence is printed
            {
                finalLength = sequenceSize;
                start = i;
            }
        }
    }
    printf("Longest common sequence is");
    
    for(int m = start; m < (start + finalLength - 1); m++)
        printf(" %d,", firstArr[m]);
        
    printf(" %d.", firstArr[start + finalLength - 1]);
    
    return;
}   

int checkNext(int first, int second, int firstSize, int secondSize, int firstArr[], int secondArr[])
{
    int sequenceSize;
    
    for(int a = 1; a < firstSize; a++)
    {
        for(int b = 1; b < secondSize; b++)
        {
            if(firstArr[first + a] == secondArr[second + b])
                sequenceSize++;
            
            else
                sequenceSize = 1;
        }
    }
    return sequenceSize;
}
