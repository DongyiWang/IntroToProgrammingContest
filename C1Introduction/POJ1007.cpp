/*POJ1007
Description: One measure of ``unsortedness'' in a sequence is the number of pairs of entries that are out of order with respect to each other. For instance, in the letter sequence ``DAABEC'', this measure is 5, since D is greater than four letters to its right and E is greater than one letter to its right. This measure is called the number of inversions in the sequence. The sequence ``AACEDGG'' has only one inversion (E and D)---it is nearly sorted---while the sequence ``ZWQM'' has 6 inversions (it is as unsorted as can be---exactly the reverse of sorted).
You are responsible for cataloguing a sequence of DNA strings (sequences containing only the four letters A, C, G, and T). However, you want to catalog them, not in alphabetical order, but rather in order of ``sortedness'', from ``most sorted'' to ``least sorted''. All the strings are of the same length. 

Input: The first line contains two integers: a positive integer n (0 < n <= 50) giving the length of the strings; and a positive integer m (0 < m <= 100) giving the number of strings. These are followed by m lines, each containing a string of length n. 

Output: Output the list of input strings, arranged from ``most sorted'' to ``least sorted''. Since two strings can be equally sorted, then output them according to the orginal order. 

Strategy: start from the end */

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class POJ1007
{
public:
  POJ1007();
  ~POJ1007();
  void input();
  void output();
private:
  int n, m;
  string* mystr;
  int invert_num(string singlestring);
  int* mysort();
};

POJ1007::POJ1007()
{
}

POJ1007::~POJ1007()
{
}

void POJ1007::input()
{
  cout << "Please input the length n: ";
  cin >> n;
  cout << "Please input the string number m: ";
  cin >> m;
  mystr = new string[m];
  for(int i=1; i<=m; i++)
    {
      cout << "Please input the string" << i << ":";
      cin >> mystr[i-1];
    }
}

void POJ1007::output()
{
  int* index = mysort();
  for(int i=0; i<m; i++)
    {
      cout << mystr[index[i]] << endl;
    }
}

int POJ1007::invert_num(string singlestring)
{
  char ch;
  int a[4] = {0};
  int inum = 0;
  for(int i=n-1; i>=0; i--)
    {
      ch = singlestring.at(i);
      switch(ch)
	{
	case 'A':
	  a[1]++;
	  a[2]++;
	  a[3]++;
	  break;
	case 'C':
	  a[2]++;
	  a[3]++;
	  inum += a[1];
	  break;
	case 'G':
	  a[3]++;
	  inum += a[2];
	  break;
	case 'T':
	  inum += a[3];
	  break;
	}
    }
  return inum;
}

int* POJ1007::mysort()
{
  int* inum = new int[m];
  int* index = new int[m];
  for(int i=0; i<m; i++)
    {
      inum[i] = invert_num(mystr[i]);
      index[i] = i;
    }
  for(int i=0; i<m; i++)
    for(int j=i+1;j<m; j++)
      if(inum[j]<inum[i])
	{
	  int temp = inum[j];
	  inum[j] = inum[i];
	  inum[i] = temp;
	  temp = index[j];
	  index[j] = index[i];
	  index[i] = temp;
	}
  return index;
}

int main(int argc, char** argv)
{
  POJ1007 test;
  test.input();
  test.output();
  return 0;
}



