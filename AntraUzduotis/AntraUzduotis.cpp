// Author: Rokas Karosas
// Date: 2023 October

#include <iostream>
#include <string>

using namespace std;

// User selects whether he would like to encrypt or decrypt a word.
int ActionSelectionTable() {
	cout << "Pasirinkite, veiksmo, kuri norite atlikti, skaiciu." << endl;
	cout << "1. Uzsifruoti zodi." << endl;
	cout << "2. Desifruoti zodi." << endl;
	cout << "3. Uzsifruoti zodi naudojant tik ASCII lentele." << endl;
	cout << "4. Desifruoti zodi naudojant tik ASCII lenetele" << endl;

	int action;
	cin >> action;
	// Next input command is getline.
	cin.ignore();
	return action;
}

// Used for getting TEXT and KEY strings.
void KeyAndText(string &text, string &key) {
	
	// TEXT
	cout << "Iveskite turima zodi:";
	getline(cin, text);
	for (int i = 0; i < text.length(); i++) {
		text[i] = toupper(text[i]);
	}

	// KEY
	cout << "Iveskite sifravimo rakta: ";
	getline(cin, key);
	for (int i = 0; i < key.length(); i++) {
		key[i] = toupper(key[i]);
	}
}

// 
void Encryption(char Alphabet[], string text, string key, char cipher_text[]) {
	int encryption_index;
	int j = 0;

	for (int i = 0; i < text.length(); i++) {
		// Checks if j value is at last KEY string position.
		if (j >= key.length()) {
			j = 0;
		}
		// Capital letters in the ASCII table begin with the value of 65 and end with 90.
		encryption_index = ((int(text[i]) + int(key[j]) - 130) % 26);
		//cout << j << " " << int(text[i]) - 65 << " " << int(key[j]) - 65 << " " << ((int(text[i]) + int(key[j]) - 130) % 26) << endl;
		cipher_text[i] = Alphabet[encryption_index];
		j++;
	}
}

void Decryption(char Alphabet[], string text, string key, char decipher_text[]) {
	int decryption_index;
	int j = 0;

	for (int i = 0; i < text.length(); i++) {
		// Checks if j value is at last KEY string position.
		if (j >= key.length()) {
			j = 0;
		}
		// Capital letters in the ASCII table begin with the value of 65 and end with 90.
		decryption_index = ((int(text[i]) - int(key[j]) + 26) % 26);
		decipher_text[i] = Alphabet[decryption_index];
		//cout << decipher_text << " " << ((int(text[i]) - int(key[j]) + 26) % 26) << " " << text[i] << " " << key[j] << endl;
		j++;
	}
}

void EncryptWithAscii(string text, string key, char cipher_text[]) {
	int encryption_index;
	int j = 0;

	for (int i = 0; i < text.length(); i++) {
		// Checks if j value is at last KEY string position.
		if (j >= key.length()) {
			j = 0;
		}
		// Capital letters in the ASCII table begin with the value of 65 and end with 90.
		encryption_index = ((int(text[i]) + int(key[j]) - 130) % 26);
		//cout << j << " " << int(text[i]) - 65 << " " << int(key[j]) - 65 << " " << ((int(text[i]) + int(key[j]) - 130) % 26) << endl;
		cipher_text[i] = char('A' + encryption_index);
		j++;
	}
}

void DecryptWithAscii(string text, string key, char decipher_text[]) {
	int decryption_index;
	int j = 0;

	for (int i = 0; i < text.length(); i++) {
		// Checks if j value is at last KEY string position.
		if (j >= key.length()) {
			j = 0;
		}
		// Capital letters in the ASCII table begin with the value of 65 and end with 90.
		decryption_index = ((int(text[i]) - int(key[j]) + 26) % 26);
		decipher_text[i] = char('A' + decryption_index);
		//cout << decipher_text << " " << ((int(text[i]) - int(key[j]) + 26) % 26) << " " << text[i] << " " << key[j] << endl;
		j++;
	}
}

int main()
{
	// Used for storing user action value.
	int action;
	action = ActionSelectionTable();

	char Alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	string text;
	string key;

	// Initializing memory for array.
	char cipher_text[100] = "";
	
	KeyAndText(text, key);
	
	switch (action) {
	case 1: Encryption(Alphabet, text, key, cipher_text);
		break;
	case 2: Decryption(Alphabet, text, key, cipher_text);
		break;
	case 3: EncryptWithAscii(text, key, cipher_text);
		break;
	case 4: DecryptWithAscii(text, key, cipher_text);
		break;
	}
	// Printing encrypted/decrypted string.
	for (int i = 0; i < text.length(); i++) {
		cout << cipher_text[i];
	}
	cout << endl;
	system("pause");
	return 0;
}