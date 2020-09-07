#include <iostream>
#include <vector>


using namespace std;


class Enemy {
public:
	Enemy() { dmg = 0; }
	Enemy(int _dmg) :dmg(_dmg) {}
	virtual void Attack() {
		cout << "Az ellenfel " << dmg << " sebzest okozott. " << endl;
	}
	virtual ~Enemy() {}
protected:
	int dmg;
};

class Monster : public Enemy {
public:
	Monster() :Enemy() {}
	Monster(int _dmg) :Enemy(_dmg) {}
	void Attack() {
		cout << "A szorny " << dmg << " sebzett okozott Neked " << endl;
	}
	virtual ~Monster() {};
};

class Dragon : public Enemy {
public:
	Dragon() :Enemy() {}
	Dragon(int _dmg) :Enemy(_dmg) {}
	void Attack() {
		cout << "A sarkany " << dmg << " sebzett okozott Neked " << endl;
	}
	virtual ~Dragon() {};
};

int main() {
	Enemy e(120);
	Monster m(130);
	Dragon d(465);

	vector<Enemy*> ellenfelek;
	ellenfelek.push_back(&e);
	ellenfelek.push_back(&m);
	ellenfelek.push_back(&d);

	for (unsigned int i = 0; i < ellenfelek.size(); i++) {
		ellenfelek[i]->Attack();
	}
	getchar();
	return 0;
}