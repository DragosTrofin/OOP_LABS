#include <iostream>
#include <fstream>
#include<queue>
#include<utility>
#include <string>
#include <map>
using namespace std;

class comparator
{
public:
	bool operator()(const pair<string, unsigned int>& p1, const pair<string, unsigned int>& p2)
	{
		if (p1.second == p2.second)
			return p1.first > p2.first;

		return p1.second < p2.second;
	}
};
void customtolowercase(string& str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
}
void parseWords()
{
	string phrase;
	string delim(" ,.?!");
	string word;


	map<string, unsigned int> wordFreq;
	map<string, unsigned int>::iterator it;

	priority_queue<pair<string, unsigned int>, vector<pair<string,unsigned int>>, comparator>queue;
	size_t startWord, endWord;
	ifstream fileDescriptor;
	fileDescriptor.open("C:\\text.txt");
	getline(fileDescriptor, phrase);

	startWord = phrase.find_first_not_of(delim);
	while (startWord != string::npos)
	{
		endWord = phrase.find_first_of(delim, startWord);
		word = phrase.substr(startWord, endWord - startWord);
		startWord = phrase.find_first_not_of(delim,endWord);
		customtolowercase(word);
		it = wordFreq.find(word);
		if (it == wordFreq.end())
		{
			wordFreq[word] = 1;
		}
		else
		{
			wordFreq[word]++;
		}
	}

	for (it = wordFreq.begin(); it != wordFreq.end(); it++)
	{
		queue.push({ it->first, it->second });
	}
	while (queue.empty() == false)
	{
		cout << queue.top().first << " " << queue.top().second << endl;
		queue.pop();
	}
}

int main()
{
	parseWords();
}
