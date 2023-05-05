#pragma once
#ifndef SDDS_POWER_H
#define SDDS_POWER_H


namespace sdds {
	const int MAX_LEN = 50;

	class Power {
		char max_name[MAX_LEN + 1];
		int max_rarity;

	public:
		Power();
		Power(const char* name, int rarity);
		void setEmpty();
		void createPower(const char* name, int rarity);

		const char* checkName() const;
		int checkRarity() const;
		bool isEmpty() const;
	};
	void displayDetails(Power* powers, int size);
}
#endif
