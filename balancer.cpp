#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <cassert>
#include <chrono>
#include <random>
#include <iterator>
#include <algorithm>
#include <functional>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//
//#include <ext/pb_ds/assoc_container.hpp>
//#define unordered_map gp_hash_table
//using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define pa pair<int8_t, ull> 
#define pac pair<char, ull> 
#define pam pair<ll, unordered_map<ull, pac, chash>> 

using namespace std;
using __team__ = vector<string>;

class DataBase {
private:
	unordered_map<string, vector<int>> _points;
	unordered_map<string, int> _indByName;
	int _cntParametrs = 9;

public:
	// Прием		Подача		    Удар			         Блок	
	// Довод Cкор	Сила Попадан	Сила Попадан Высота	     Высота	КПД
	DataBase() {
		_points["Женя"] = { 5, 3, 7, 5, 6, 5, 3, 2, 2 };
		_points["Леша"] = { 8, 8, 8, 8, 9, 8, 8, 7, 8 };
		_points["Ваня"] = { 7, 9, 5, 9, 8, 8, 7, 6, 8 };
		_points["Дима"] = { 6, 9, 6, 4, 6, 3, 2, 1, 1 };
		_points["Степа"] = { 6, 9, 7, 4, 7, 5, 4, 3, 4 };
		_points["Алина"] = { 6, 5, 5, 8, 4, 2, 0, 0, 0 };
		_points["Тема З"] = { 6, 6, 6, 7, 6, 5, 7, 6, 8 };
		_points["Рома"] = { 6, 7, 9, 5, 9, 7, 10, 9, 7 };
		_points["Коля"] = { 6, 6, 6, 6, 7, 5, 7, 6, 5 };
		_points["Радион"] = { 5, 6, 8, 4, 8, 5, 7, 6, 7 };
		_points["Аня"] = { 6, 5, 4, 6, 2, 2, 0, 0, 0 };
		_points["Ира"] = { 3, 4, 3, 6, 3, 2, 0, 0, 0 };
		_points["Настя"] = { 5, 4, 5, 5, 4, 4, 2, 1, 1 };
		_points["Серега"] = { 6, 5, 6, 5, 5, 5, 3, 2, 1 };
		_points["Гоша"] = { 5, 6, 6, 8, 6, 6, 6, 5, 6 };
		_points["Леся"] = { 5, 3, 8, 7, 4, 5, 1, 0, 0 };
		_points["Саня Б"] = { 8, 7, 8, 7, 7, 7, 4, 3, 4 };
		_points["Катя"] = { 6, 8, 6, 8, 4, 5, 1, 0, 0 };
		_points["Саша Ф"] = { 2, 2, 3, 3, 3, 2, 3, 2, 2 };
		_points["Маша"] = { 6, 5, 5, 5, 3, 3, 0, 0, 0 };
		_points["Артем С"] = { 3, 4, 6, 6, 5, 5, 4, 4, 5 };
		_points["Вадим"] = { 6, 5, 6, 7, 6, 5, 4, 3, 4 };
		_points["Карина"] = { 3, 3, 3, 3, 2, 2, 0, 0, 0 };
		_points["Олег"] = { 6, 5, 6, 8, 7, 7, 5, 4, 6 };

		_indByName["Женя"] = 0;
		_indByName["Леша"] = 1;
		_indByName["Ваня"] = 2;
		_indByName["Дима"] = 3;
		_indByName["Степа"] = 4;
		_indByName["Алина"] = 5;
		_indByName["Тема З"] = 6;
		_indByName["Рома"] = 7;
		_indByName["Коля"] = 8;
		_indByName["Радион"] = 9;
		_indByName["Аня"] = 10;
		_indByName["Ира"] = 11;
		_indByName["Настя"] = 12;
		_indByName["Серега"] = 13;
		_indByName["Гоша"] = 14;
		_indByName["Леся"] = 15;
		_indByName["Саня Б"] = 16;
		_indByName["Катя"] = 17;
		_indByName["Саша Ф"] = 18;
		_indByName["Маша"] = 19;
		_indByName["Артем С"] = 20;
		_indByName["Вадим"] = 21;
		_indByName["Карина"] = 22;
		_indByName["Олег"] = 23;
	}

	void setPoints(const string& name, const vector<int> value) {
		_points[name] = value;
	};

	unordered_map<string, vector<int>> getPoints() {
		return _points;
	}

	int getCntParametrs() {
		return _cntParametrs;
	}

	vector<int> getPoints(const string& name) {
		auto it = _points.find(name);
		if (it == _points.end()) return vector<int>(_cntParametrs, -1);
		return it->second;
	}

	int getCntMembers() {
		return _points.size();
	}

	int getInd(const string& name) {
		return _indByName[name];
	}
};

class Members {
private:
	DataBase _db;
	__team__ _numName;

public:

	Members(): _db(DataBase()) {
		_numName = { "Женя", "Леша", "Ваня", "Дима", "Степа", "Алина", "Тема З", "Рома", "Коля", "Радион", 
					"Аня", "Ира", "Настя", "Серега", "Гоша", "Леся", "Саня Б", "Катя", "Саша Ф", "Маша", 
					"Артем С", "Вадим", "Карина", "Олег" };
	};
	
	void setPoints(const string& name, const vector<int> value) {
		_db.setPoints(name, value);
	};

	void setPoints(const int ind, const vector<int> value) {
		setPoints(_numName[ind], value);
	};

	int getCntParametrs() {
		return _db.getCntParametrs();
	}

	vector<int> getPoints(const string& name) {
		return _db.getPoints(name);
	}

	vector<int> getPoints(const int ind) {
		return getPoints(_numName[ind]);
	}

	int getCntMembers() {
		return _db.getCntMembers();
	}

	string getName(const int ind) {
		return _numName[ind];
	}

	int getInd(const string& name) {
		return _db.getInd(name);
	}
};

class Balance {
private:
	Members _members;
	__team__ _visited;
	int _cntTeams;
	const int _cntPeopleInTeam = 6;
	vector <__team__> _teams;

public:
	Balance(const __team__ visited, const int cntTeams) : _visited(visited), _cntTeams(cntTeams) {};

	vector<int> calcTeamPower(const __team__& team) {
		vector<int> teamPower(_members.getCntParametrs(), 0);
		for (auto& it : team) {
			vector<int> peoplePower = _members.getPoints(it);
			for (int i = 0; i < teamPower.size(); ++i) {
				teamPower[i] += peoplePower[i];
			}
		}

		return teamPower;
	}

	bool isBalancedTeams(const __team__& first, const __team__& second, int delta = 0) {
		auto firstPower = calcTeamPower(first);
		auto secondPower = calcTeamPower(second);
		int sumDelta = 0;
		for (int i = 0; i < _members.getCntParametrs(); ++i) {
			sumDelta += abs(firstPower[i] - secondPower[i]);
		}

		return sumDelta <= delta;
	}

	void constructUsed(vector<bool>& used) {
		used.assign(_members.getCntMembers(), true);
		for (auto& it : _visited) {
			used[_members.getInd(it)] = false;
		}
	}

	__team__ buildTeam(vector<bool>& used) {
		__team__ currentTeam;
		int cntMembers = _visited.size();
		int cntPeople = _members.getCntMembers();
		while (currentTeam.size() < _cntPeopleInTeam) {
			int numberOfPeople = rand() % cntPeople;
			if (!used[numberOfPeople]){
				currentTeam.push_back(_members.getName(numberOfPeople));
				used[numberOfPeople] = true;
			}
		}

		return currentTeam;
	}

	void constructTeams() {
		int cntMembers = _visited.size();
		vector<bool> used;
		constructUsed(used);
		_teams.assign(_cntTeams, __team__());
		for (int i = 0; i < _cntTeams; ++i) {
			_teams[i] = buildTeam(used);
		}
	}


	void balanceTeams() {
		int cntTry = 0;
		while (true) {
			constructTeams();
			if (isGoodBalance(cntTry / 1000)) {
				printTeams();
				return;
			}
			++cntTry;
		}
	}

	bool isGoodBalance(int delta = 0) {
		for (int i = 0; i < _cntTeams; ++i) {
			for (int j = 0; j < _cntTeams; ++j) {
				if (!isBalancedTeams(_teams[i], _teams[j], delta))
					return false;
			}
		}

		return true;
	}

	void printTeams() {
		//auto firstPower = calcTeamPower(_teams[0]);
		//auto secondPower = calcTeamPower(_teams[1]);
		//auto thirdPower = calcTeamPower(_teams[2]);

		//for (auto it : firstPower) {
		//	cout << it << ", ";
		//}
		//cout << '\n';

		//for (auto it : secondPower) {
		//	cout << it << ", ";
		//}
		//cout << '\n';

		///*for (auto it : thirdPower) {
		//	cout << it << ", ";
		//}
		//cout << '\n';*/

		for (int i = 0; i < _cntPeopleInTeam; ++i) {
			for (int j = 0; j < _cntTeams; ++j) {
				cout << setw(20) << _teams[j][i];
			}
			cout << '\n';
		}
	}
};

__team__ readVisiters(const int cntVisited) {
	//TODO delete next two rows
	__team__ visited(cntVisited);
	string n;

	getline(cin, n);
	for (int i = 0; i < cntVisited; ++i) {
		getline(cin, visited[i]);
	}

	return visited;
}

signed main() {
	std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	srand(time(0));
	setlocale(LC_ALL, "Russian");

	int cntVisited;
	cin >> cntVisited;
	__team__ visited = readVisiters(cntVisited);

	Balance T(visited, 2);
	T.balanceTeams();
}
