//Martha Sander - CS162 - Project2 - 04-18-2017.
//Sources: for searching a cstring within another cstring (function strstr): http://www.cplusplus.com/reference/cstring/strstr

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>

using namespace std;

const int MAX = 100;
//declare struct before any function prototype, to become available during any part of the program.
struct Song
{
	char songName[MAX];	
	char songArtist[MAX];
	char songAlbum[MAX];
	int minDuration;
	int secDuration;
};

//funcion to display menu.
void displayMenu (int& count, Song songList[]);
//function to open file, validade if right file is open and load data.
void openFile (const char fileName[], int& count, Song songList[]);
//function to add information for new song.
void addSong (int& count, Song songList[]);
//function to show all songs and index for each song.
void showSongs (int count, Song songList[]);
//function to remove a song by index.
void removeSong (int& count, Song songList[]);
//function to show songs by artist
void showArtist (int count, Song songList[]);
//function to show songs by album
void showAlbum (int count, Song songList[]);
//function to save new songs to file.
void saveFile (const char fileName[], int& count, Song songList[]);

int main ()
{
	char fileName[MAX] = "songs.text";
	Song songList[MAX];
	int count = 0;

	cout << "Opening file " << fileName << endl;
	openFile(fileName, count, songList);
	cout << "Welcome to your songs library!" << endl << endl;
	displayMenu(count, songList);
    return 0;
}
//function to display menu options.
//passing count as reference instead of value.
void displayMenu (int& count, Song songList[]) 
{
	char userChoice;
	char fileName[MAX] = "songs.text";
	do
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "Show all (S)ongs and index" << endl;
		cout << "Show songs by (A)rtist" << endl;
		cout << "Show songs by al(B)um" << endl;
		cout << "(R)emove songs by index" << endl;
		cout << "Add (N)ew songs to library" << endl;
		cout << "Sa(V)e library" << endl;
		cout << "(Q)uit program" << endl;
		cin >> userChoice;
		cin.ignore(MAX, '\n');
		
		//calling functions showArtist, showAlbum, removeSong, addSong and saveFile inside of switch.
		switch (toupper(userChoice))
		{
			case 'S':
				showSongs(count, songList);
				break;
			case 'A':
				showArtist(count, songList);
				break;
			case 'B':
				showAlbum (count, songList);
				break;
			case 'R':
				removeSong(count, songList);
				break;
			case 'N':
				addSong(count, songList);
				break;
			case 'V':
				saveFile (fileName, count, songList);
				break;
			case 'Q':
				break;
			default:
				cin.clear();
				cout << "Oooops, option unaveilable! Please try again" << endl << endl;
				break;
		}	
	}
	while ((toupper(userChoice)) != 'Q');
}
//function to open file and validade if right file is open.
//This function reads and store the data from the file.
void openFile (const char fileName[], int& count, Song songList[])
{
	ifstream inFile;
	ofstream outFile;
	
	inFile.open(fileName);
	//Check if file opens, print error message if it doesn't and exit program.
	if (! inFile.is_open())
	{
		cout << "Error opening file. Please verify if " << fileName << " is saved on the same directory" << endl;
		exit(0);
	}
	else
	{
		//read the data in the file into artist and album arrays, and return the number of songs read.	
		inFile.get(songList[count].songName, MAX, ';');
		inFile.ignore (100, ';');
		inFile.get(songList[count].songArtist, MAX, ';'); 
		inFile.ignore (100, ';');
		inFile >> songList[count].minDuration;
		inFile.ignore (100, ';');
		inFile >> songList[count].secDuration;
		inFile.ignore (100, ';');
		inFile.get(songList[count].songAlbum, MAX, '\n');
		inFile.ignore (100, '\n');

		while ((count < MAX) && (!inFile.eof()))
		{
			count ++;
			inFile.get(songList[count].songName, MAX, ';');
			inFile.ignore (100, ';');
			inFile.get(songList[count].songArtist, MAX, ';'); 
			inFile.ignore (100, ';');
			inFile >> songList[count].minDuration;
			inFile.ignore (100, ';');
			inFile >> songList[count].secDuration;
			inFile.ignore (100, ';');
			inFile.get(songList[count].songAlbum, MAX, '\n');
			inFile.ignore (100, '\n');
		}
	}
	inFile.close();
	inFile.clear();
}

//function addSong.
void addSong (int& count, Song songList[])
{
	char song[MAX], artist[MAX], album[MAX];
	char userChoice = 'Y';
	int minutes, seconds;

	while(((toupper(userChoice)) == 'Y'))
	{
		cout << "Enter song name: ";
		cin.getline(song, MAX, '\n');
		cout << "Enter artist name: ";
		cin.getline(artist, MAX, '\n');
		cout << "Enter song duration minutes: ";
		cin >> minutes;
		cin.clear();
		cin.ignore();
		cout << "Enter song duration seconds: ";
		cin >> seconds;
		cin.clear();
		cin.ignore();
		cout << "Enter album name: ";
		cin.getline(album, MAX, '\n');
			
		//echo to user and get confirmation.
		cout << "You entered: " << song << ", " << artist << ", " << minutes << ":" << seconds << ", " << album << endl;
		cout << "Is that correct? (Y)es or (N)o: ";
		cin.get(userChoice);
		//copy information to songList.
		if (toupper(userChoice) == 'Y')
		{
			strcpy(songList[count].songName, song);
			strcpy(songList[count].songArtist, artist);
			songList[count].minDuration = minutes;
			songList[count].secDuration = seconds;
			strcpy(songList[count].songAlbum, album);
			count++;
		}
		else
		{
			cout << "Discarding song information" << endl;
		}
	
		cin.ignore (MAX, '\n');
		cout << "Would you like to add another song? (Y)es or (N)o: ";
		cin.get(userChoice);
		cin.ignore(MAX, '\n');
	}
}	

//function to show all songs and index for each song.
void showSongs (int count, Song songList[])
{
	if (count <= 0)
	{
		cout << endl;
		cout << "The library is empty! How about adding some new songs?" << endl;
	}
	else
	{
		for (int index = 0; index < count; index++)
		{
			cout << endl;
			cout << "Index: " << index << endl;
			cout << "Name: " << songList[index].songName << endl;
			cout << "Artist: " << songList[index].songArtist << endl;
			cout << "Duration: " << songList[index].minDuration << ":" << songList[index].secDuration << endl;
			cout << "Album: " << songList[index].songAlbum << endl << endl;
		}
	}
}

//function to remove a song by index.
void removeSong (int& count, Song songList[])
{
	int userIndex;

	cout << "Please enter index of the song to be removed: ";
	cin >> userIndex;
	
	for (int index = 0; index < count; index++)
	{
		if (index == userIndex)
		{
			for (index; index < count-1; index++)
			{
				strcpy(songList[index].songName, songList[index + 1].songName);
				strcpy(songList[index].songArtist, songList[index + 1].songArtist);
				songList[index].minDuration = songList[index + 1].minDuration;
				songList[index].secDuration = songList[index + 1].secDuration;
				strcpy(songList[index].songAlbum, songList[index + 1].songAlbum);
			}
			count--;
		}
	}
	cout << "Song at " << userIndex << " removed from library" << endl << endl;
	cin.ignore(MAX, '\n');
}	
//function to show songs by artist
void showArtist (int count, Song songList[])
{
	char artist[MAX];
	int artistCount = 0;

	cout << "Please enter artist name: ";
	cin.getline (artist, MAX, '\n');	
	
	for (int index = 0; index < count; index++)
	{
		if (strcasestr(songList[index].songArtist, artist))
		{
			artistCount++;
			cout << endl;
			cout << "Index: " << index << endl;
			cout << "Name: " << songList[index].songName << endl;
			cout << "Artist: " << songList[index].songArtist << endl;
			cout << "Duration: " << songList[index].minDuration << ":" << songList[index].secDuration << endl;
			cout << "Album: " << songList[index].songAlbum << endl << endl;
		} 
	}
	if (artistCount == 0)
	{
		cout << endl;
		cout << "Sorry, there are no songs for this artist" << endl << endl;
	}
}	

//function to show songs by album
void showAlbum (int count, Song songList[])
{
	char album[MAX];
	int albumCount = 0;

	cout << "Please enter album name: ";
	cin.getline (album, MAX, '\n');	
	
	for (int index = 0; index < count; index++)
	{
		if (strcasestr(songList[index].songAlbum, album))
		{
			albumCount++;
			cout << endl;
			cout << "Index: " << index << endl;
			cout << "Name: " << songList[index].songName << endl;
			cout << "Artist: " << songList[index].songArtist << endl;
			cout << "Duration: " << songList[index].minDuration << ":" << songList[index].secDuration << endl;
			cout << "Album: " << songList[index].songAlbum << endl << endl;
		} 
	}
	if (albumCount == 0)
	{
		cout << endl;
		cout << "Sorry, there are no songs with this album name" << endl << endl;
	}
}
//function to save new songs to file.
void saveFile (const char fileName[], int& count, Song songList[])
{
	ofstream outFile;

	outFile.open(fileName);
	for (int index = 0; index < count; index++)
	{
		outFile << songList[index].songName << ";" << songList[index].songArtist << ";" << songList[index].minDuration << ";" << songList[index].secDuration << ";" << songList[index].songAlbum << endl;
	}
	cout << endl;
	cout << "Library saved!" << endl << endl;
	outFile.close();
}


