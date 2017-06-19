/*POJ1004
Description: Larry graduated this year and finally has a job. He's making a lot of money, but somehow never seems to have enough. Larry has decided that he needs to grab hold of his financial portfolio and solve his financing problems. The first step is to figure out what's been going on with his money. Larry has his bank account statements and wants to see how much money he has. Help Larry by writing a program to take his closing balance from each of the past twelve months and calculate his average account balance. 
Input: The input will be twelve lines. Each line will contain the closing balance of his bank account for a particular month. Each number will be positive and displayed to the penny. No dollar sign will be included.
Output: The output will be a single number, the average (mean) of the closing balances for the twelve months. It will be rounded to the nearest penny, preceded immediately by a dollar sign, and followed by the end-of-line. There will be no other spaces or characters in the output. */

#include<iostream>
using namespace std;
class POJ1004
{
 public:
  POJ1004();
  ~POJ1004();
  void input();
  void output();
  void MEAN();
 private:	
  float myRound(float number);
  static const int MM=12;
  float m_avg;
  float m_input[MM];	
};

POJ1004::POJ1004()
{	
  m_avg = 0;
}

POJ1004::~POJ1004()
{
	
}

void POJ1004::input()
{
  for(int i = 0; i != MM; i++)
    {
      cin >> m_input[i];
    }
}

void POJ1004::output()
{
  cout << "the average is:" << m_avg << endl;
}

void POJ1004::MEAN()
{
  float sum = 0;
  for(int i = 0; i != MM; i++)
    {
      sum += m_input[i];
    }
  m_avg = myRound(sum / MM);
}

float POJ1004::myRound(float number)
{
  number = float(number * 100 + 0.5);
  number = number / 100;
  return number;
}

int main(int argc, char ** argv)
{
  POJ1004 test;
  test.input();
  test.MEAN();
  test.output();
  return 0;
}
