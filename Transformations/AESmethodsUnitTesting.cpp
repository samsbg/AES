#include "subByteSubstitutionUnitTesting.cpp"
#include "addRoundKeyUnitTesting.cpp"
#include "keyTransformationUnitTesting.cpp"

#include <iostream>
using namespace std;

int main()
{
    int correctCount = 0;
    int totalCorrectCount = 0;
    int count = 0;
    int totalCount = 0;

    if (subByteSubstitutionTest1())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (subByteSubstitutionTest2())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (subByteSubstitutionTest3())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (subByteSubstitutionTest4())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;

    cout << "SubByte substitution test " << correctCount << "/" << count << ": " << ((correctCount == count) ? "Success" : "Failed") << endl;

    correctCount = 0;
    count = 0;

    if (addRoundKeyTest1())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (addRoundKeyTest2())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;

    cout << "Add round key test " << correctCount << "/" << count << ": " << ((correctCount == count) ? "Success" : "Failed") << endl;

    correctCount = 0;
    count = 0;

    if (keyTransformationTest1())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest2())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest3())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest4())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest5())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest6())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest7())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest8())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest9())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest10())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest11())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest12())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest13())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest14())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;
    if (keyTransformationTest15())
    {
        correctCount++;
        totalCorrectCount++;
    }
    count++;
    totalCount++;

    cout << "Key transformation test " << correctCount << "/" << count << ": " << ((correctCount == count) ? "Success" : "Failed") << endl;

    correctCount = 0;
    count = 0;

    cout << " -> AES methods test " << totalCorrectCount << "/" << totalCount << ": " << ((totalCorrectCount == totalCount) ? "Success" : "Failed") << endl;

    return 0;
}