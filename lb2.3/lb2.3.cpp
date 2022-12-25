#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string artists() {
	string id;
	string Name;

	ifstream infile("artists.csv");
	string line;
	while (getline(infile, line)) {
		stringstream iss(line);
		getline(iss, id, ';');
		getline(iss, Name, ',');
		if (Name == "Guns N' Roses")
		{
			//cout << id << "\t" << Name << endl;
			return  id;
		}
	}
}

vector <string> album(string idGR) {
	string id;
	string name_album;
	string id_name;
	vector <string> array;
	ifstream infile("albums.csv");
	string line;
	while (getline(infile, line)) {
		stringstream iss(line);
		getline(iss, id_name, ';');
		getline(iss, name_album, ';');
		getline(iss, id, ',');
		if (id == idGR)
			array.push_back(id_name);

	}
	return array;
}

int tracks(vector <string> array) {
	string id_tracks;
	string name_album;
	string id_album;
	string id_genres;
	string duration;
	ifstream infile("tracks.csv");
	string line;
	int sum = 0;
	while (getline(infile, line)) {
		stringstream iss(line);
		getline(iss, id_tracks, ';');
		getline(iss, name_album, ';');
		getline(iss, id_album, ';');
		getline(iss, id_genres, ';');
		getline(iss, duration, ';');
		if (find(array.begin(), array.end(), id_album) != array.end())
			sum += stoi(duration);
	}
	return sum / 60000;
}

/*
18) (А. Кабанов) Используя информацию из базы данных в файле 3-5.xls,
определите, сколько минут длятся все песни группы Guns N' Roses.
В ответе укажите целую часть получившегося числа.
Ответ - 205 +
*/

int main() {
	setlocale(LC_ALL, "RUS");
	string id_GR = artists();
	vector <string> array = album(id_GR);
	cout << array.size() << endl;
	int sum = tracks(array);
	cout << sum << endl;
}