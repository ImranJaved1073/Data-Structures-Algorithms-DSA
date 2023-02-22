// ================================================================================================
// QUESTION:
/*
We have a playlist of N songs numbered from 1 to N. 
Song i lasts Ai seconds.
When the playlist is played, the songs are played in order from 1 to N,
When the last song (N) ends, the playlist repeats from the beginning.
While a song is playing, the next song does not play: 
when a song ends, the next song starts immediately.
At exactly T seconds after the playlist starts playing,which song is playing?
Also, how many seconds have elapsed since the beginning of the song?
There is no input where the playlist changes songs at exactly T seconds after the playlist starts playing.
*/
//==================================================================================================
#include <iostream>
#include <string>

using namespace std;

pair<int, int> getSongNumberWithTime(int N, int T, int songLengths[])
{
	if (N == 0)
		return make_pair(0, 0);

	int lengthOfPlaylist = 0;
	for (int i = 0; i < N; i++)
		lengthOfPlaylist += songLengths[i];

	int time = T % lengthOfPlaylist;
	int song = 0;

	while (time >= songLengths[song])
	{
		time -= songLengths[song];
		song++;
	}
	return make_pair(song + 1, time);
}

int main()
{
	const int N = 3;
	int T;
	cin >> T;
	int songLengths[N] = { 0 };
	for (int i = 0; i < N; i++)
		cin >> songLengths[i];

	pair<int, int> song = getSongNumberWithTime(N, T, songLengths);
	cout << "Song Number: " << song.first << endl;
	cout << "Seconds Elapsed: " << song.second << endl;
}