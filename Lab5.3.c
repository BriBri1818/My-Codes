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

    for (int i = 0; i < sizeA; i++) //will check every index in the array 
    {
        for(int j = 0; j < sizeB; j++)
        {
            if(firstArr[i] == secondArr[j])
                sequenceSize = checkNext(i, j, sizeA, sizeB, firstArr, secondArr);
            
            else 
            {
                for(int k = 1; k < sizeB; k++)
                {
                    int nextJ = j + k;
                    if(firstArr[i] == secondArr[nextJ])
                        sequenceSize = checkNext(i, nextJ, sizeA, sizeB, firstArr, secondArr);
                        
                    else
                        sequenceSize = 0;
                }
            }
            
            if(sequenceSize > finalLength)
            {
                finalLength = sequenceSize;
                start = i;
            }
        }
    }
    printf("Longest Common Sequence is");
    
    for(int m = start; m < (start + sequenceSize); m++)
        printf(" %d,", firstArr[m]);
        
    printf(" %d.", firstArr[start + sequenceSize]);
    
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


