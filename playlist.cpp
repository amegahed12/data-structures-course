#include <iostream>
#include <string>

using namespace std;

// Structure to represent a song in the playlist
struct Song
{
    string title;  // Title of the song
    string artist; // Artist of the song
    Song *prev;    // Pointer to the previous song in the list
    Song *next;    // Pointer to the next song in the list

    // Constructor to initialize a song with a title and artist
    Song(string t, string a)
    {
        title = t;
        artist = a;
        prev = 0;
        next = 0;
    }
};

// doubly doubly playlist
struct Playlist
{

    Song *head;
    Song *tail;    // Pointer to the last song in the playlist
    Song *playing; // current song playing

    // Constructor to initialize an empty playlist
    Playlist()
    {
        head = 0;
        tail = 0;
        playing = 0;
    }

    //////////////////////////////////////_/  Add a song to the playlist  /_//////////////////////////////////////////////////////
    void addSong(string title, string artist)
    {
        // Create a new song object
        Song *newSong = new Song(title, artist);

        // If the playlist is empty
        if (!head)
            head = tail = newSong;

        else
        {
            tail->next = newSong; // Link the new song to the end of the list
            newSong->prev = tail; // Link the previous tail to the new song
            tail = newSong;       // Update the tail to the new song
        }
        cout << "Song added: " << title << " by " << artist << '\n';
    }

    //////////////////////////////////////_/  Delete a song by its title  /_//////////////////////////////////////////////////////
    void deleteSong(string title)
    {
        Song *current = head;

        // Search the list to find the song
        while (current)
        {

            // If we found the song
            if (current->title == title)
            {

                // Check if we are on the head or not
                // If not, update the previous song's next pointer
                if (current->prev)
                    current->prev->next = current->next;
                else
                    // We are on the head
                    // Update the head if the first song is deleted
                    head = current->next;

                // Check if we are on the tail or not
                // if not, update the next song's prev pointer
                if (current->next)
                    current->next->prev = current->prev;
                else
                    // We are on the tail
                    // Update the tail if the last song is deleted
                    tail = current->prev;

                // Get rid of this garbage song aka Om Kalthoum songs
                delete current;

                cout << "Song deleted: " << title << '\n';

                // TARGET FOUND, get out of the function, I repeat get out   0-:
                return;
            }

            // Moving to the next song because the current is not the song we are looking for
            current = current->next;
        }
        cout << "Song not found: " << title << '\n';
    }

    //////////////////////////////////////_/  Search for a song by its title  /_//////////////////////////////////////////////////////
    void searchSong(string title)
    {
        Song *current = head;

        // Search the list to find the song
        while (current)
        {
            // If we found the song we are looking for
            if (current->title == title)
            {
                cout << "Song found: " << title << " by " << current->artist << '\n';
                return;
            }

            // Moving to the next song, if not found
            current = current->next;
        }
        cout << "Song not found: " << title << '\n';
    }

    //////////////////////////////////////_/  Play a specific song by title  /_//////////////////////////////////////////////////////
    void playSong(string title)
    {
        Song *current = head;

        // Search the list to find the song
        while (current)
        {

            // if we found the song
            if (current->title == title)
            {
                cout << "Playing: " << current->title << " by " << current->artist << '\n';

                // Store the song we are playing, so we can go prev or next
                playing = current;
                return;
            }

            // Moving to the next song, if it's not the one we are looking for
            current = current->next;
        }
        cout << "Song not found: " << title << '\n';
    }

    //////////////////////////////////////_/  Play the song before the currently playing  /_//////////////////////////////////////////////////////
    void playPrevious()
    {

        // if there is a song currently playing
        if (playing)
        {
            // Change the current playing to be the previous
            playing = playing->prev;

            if (playing)
                cout << "playing " << playing->title << " by " << playing->artist;
            else
                cout << "No prev song to play";
        }
        else
        {
            cout << "No song playing!";
        }
    }

    //////////////////////////////////////_/  Play the song after the currently playing  /_//////////////////////////////////////////////////////
    void playNext()
    {

        // If there is a song currently playing
        if (playing)
        {
            // Change the current playing to be the after
            playing = playing->next;

            // check if we are in the end or not
            if (playing)
                cout << "playing " << playing->title << " by " << playing->artist;
            else
                cout << "No next song to play";
        }
        else
            cout << "No song playing!";
    }

    //////////////////////////////////////_/  Display all songs in the playlist  /_//////////////////////////////////////////////////////
    void displayPlaylist()
    {
        // If the playlist is empty
        if (!head)
        {
            cout << "The playlist is empty.\n";

            // Get out of the function, nothing to display
            return;
        }

        Song *current = head;

        // Iterate on each song and display it
        while (current)
        {
            cout << current->title << " by " << current->artist << '\n';
            current = current->next;
        }
    }

    void playReverse()
    {

        // if song is empty
        if (!tail)
        {
            cout << "The playlist is empty.\n";
            return;
        }

        // Start from the last song
        Song *current = tail;

        cout << "Playing songs from the end to the start:\n";

        // Play from last finish
        while (current)
        {
            cout << "Playing: " << current->title << " by " << current->artist << '\n';
            current = current->prev; // Go to the song before
        }
    }
};

int main()
{
    // Create a playlist object
    Playlist playlist;

    // Variable to store user choice
    char choice;
    string title, artist;

    /////////////////////  Add song samples  ////////////////////////////////
    playlist.addSong("Song_1", "Artist_1");
    playlist.addSong("Song_2", "Artist_1");
    playlist.addSong("Song_3", "Artist_2");
    playlist.addSong("Song_4", "Artist_2");
    playlist.addSong("Song_5", "Artist_2");
    playlist.addSong("Song_6", "Artist_3");
    playlist.addSong("Song_7", "Artist_3");
    playlist.addSong("Song_8", "Artist_3");
    playlist.addSong("Song_9", "Artist_3");
    //////////////////////////////////////////////////////////////////////////

    cout << "\n== Welcome to our Music App! ==\n";
    do
    {
        // Display the menu options
        cout << "\n= - = - = Playlist Menu = - = - =\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Search Song\n";
        cout << "4. Play a Song\n";
        cout << "5. Play Previous Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Display Playlist\n";
        cout << "8. Play Songs in Reverse Order\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            // Add a new song to the playlist
            cout << "Enter song title: ";
            cin >> title;
            cout << "Enter artist name: ";
            cin >> artist;
            playlist.addSong(title, artist);
            break;
        case '2':
            // Delete a song by title
            cout << "Enter song title to delete: ";
            cin >> title;
            playlist.deleteSong(title);
            break;
        case '3':
            // Search for a song by title
            cout << "Enter song title to search: ";
            cin >> title;
            playlist.searchSong(title);
            break;
        case '4':
            // Play a specific song by title
            cout << "Enter song title to play: ";
            cin >> title;
            playlist.playSong(title);
            break;
        case '5':
            // Play the previous song
            playlist.playPrevious();
            break;
        case '6':
            // Play the next song
            playlist.playNext();
            break;
        case '7':
            // Display all songs in the playlist
            playlist.displayPlaylist();
            break;
        case '8':
            // Play in reverse order
            playlist.playReverse();
            break;
        case '9':
            // Stop
            cout << "Exiting the program.\n";
            break;
        default:
            // If user chooses an option that does not exist
            cout << "Invalid choice. Please try again.\n";
        }
    }
    // Repeat until the user chooses to exit
    while (choice != '8');

    return 0;
}
