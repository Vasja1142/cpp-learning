#include "Money.h"

Money::Money() {
	rub = 0;
	cop = 0;
}
Money::Money(long r, int c) {
	rub = r;
	cop = c;
}
Money::Money(Money& m) {
	rub = m.rub;
	cop = m.cop;
}

void Money::printMoney() {
	setlocale(LC_ALL, "Ru");
	cout << "�� ����� �����:\n";
	cout << rub << " ������\n";
	cout << cop << " ������\n";
	if (rub < 1000) cout << "�� ��������!\n";
	else if (rub < 10000) cout << "�������� �� �����\n";
	else if (rub < 100000)cout << "��� �������. �������!\n";
	else cout << "��������?\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

Money Money::operator*(double val) const
{
	Money m(rub * val, cop * val);
	return m;
}

Money Money::operator/(int val) const {
	Money m(rub / val, cop / val);
	return m;
}

Money& Money::operator=(const Money& m)
{
	Money n(m.rub, m.cop);
	this->rub = m.rub;
	this->cop = m.cop;
	return n;
}
