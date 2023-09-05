#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

struct distance {
    float euclidiean;
    float manhattan;
    float minkowski;
};

struct detail {
    char character;
    int repeated;
    bool isChecked;
};

struct information {
    int ID;
    string DNA;
    int length;
    struct detail info[25];
    int ascii[25];
    int binary[25][7];
    int similarity;
    struct distance interval;
    int shift;
    string encrypted;
    string decrypted;
};

class App {
    private: 
        fstream file;
        fstream results;
        struct information dataset[51];
        struct information target;


        /**
         * @brief Takes an array of characters then returns a string object. 
         * 
         * @param characters Required. array of characters
         * @param size Required. size of the array of characters
         * @return string object.
         */
        string flatten(char characters[], int size) {
            string result;

            if (size == 9) {
                result = "00000000";
            }
            else if (size == 26) {
                result = "0000000000000000000000000";
            }

            for (int i = 0; i < size; i++) {
                if (size == 9 && i == 0) {
                    continue;
                }
                if (size == 9 && i == 8) {
                    continue;
                }
                if (size == 26 && i == 25) {
                    continue;
                }

                result[i] = characters[i];
            }

            return result;
        }


        /**
         * @brief Prints menu and prompt at the end.
         * 
         */
        void print() {
            cout << endl;
            cout << "1.  Input" << endl;
            cout << "2.  Output" << endl;
            cout << "3.  Count" << endl;
            cout << "4.  Convert" << endl;
            cout << "5.  Reduce" << endl;
            cout << "6.  Target" << endl;
            cout << "7.  Compare" << endl;
            cout << "8.  Search" << endl;
            cout << "9.  Distance" << endl;
            cout << "10. Encrypt" << endl;
            cout << "11. Decrypt" << endl;
            cout << "12. Save" << endl;
            cout << "13. Exit" <<  endl;
            cout << endl;
            cout << ">>> ";
        }


        /**
         * @brief Reads file and manages the information.
         * 
         */
        void get() {
            char ID[9];
            char DNA[26];
            int turn = 0;
            int queue = 0;

            while(!file.eof()) {
                if (turn % 2 == 0) {
                    file.getline(ID, 9);
                    dataset[queue].ID = stoi(flatten(ID, 9));
                    turn++;
                }
                else {
                    file.getline(DNA, 26);
                    dataset[queue].DNA = flatten(DNA, 26);
                    dataset[queue].length = 25;
                    turn++;
                    queue++;
                }
            }
        }


        /**
         * @brief Takes a decimal number and calculates it's binary value.
         * 
         * @param binary Required. array to store binary code
         * @param decimal Required. decimal number to be converted
         */
        void bin(int binary[], int decimal) {
            int i = 6;

            while(decimal > 0) {
                binary[i] = decimal % 2;
                decimal /= 2;
                i--;
            }
        }

        /**
         * @brief Calculates euclidean distance.
         * 
         * @param target Required. array of X
         * @param opponent Required. array of Y
         * @param size Required. size of both arrays
         * @return float object
         */
        float euclidean(int target[], int opponent[], int size) {
            float difference = 0;
            float result;
            float power;

            for(int i = 0; i < size; i++) {
                power = pow((target[i] - opponent[i]), 2);
                difference += power;
            }

            result = sqrt(difference);
            return result;
        }

        /**
         * @brief Calculates manhattan distance.
         * 
         * @param target Required. array of X 
         * @param opponent Required. array of Y 
         * @param size Required. size of both arrays 
         * @return float float object 
         */
        float manhattan(int target[], int opponent[], int size) {
            float difference = 0;
            float absolute;

            for(int i = 0; i < size; i++) {
                absolute = abs(target[i] - opponent[i]);
                difference += absolute;
            }

            return difference;
        }

        /**
         * @brief Calculates minkowski distance.
         * 
         * @param target Required. array of X 
         * @param opponent Required. array of Y 
         * @param size Required. size of both arrays 
         * @param purpose Required. int as purpose
         * @return float float object 
         */
        float minkowski(int target[], int opponent[], int size, int purpose) {
            float difference = 0;
            float expotential;
            float result;
            float power;

            for(int i = 0; i < size; i++) {
                power = pow(abs(target[i] - opponent[i]), purpose);
                difference += power;
            }

            expotential = 1.0 / purpose;
            result = pow(difference, expotential);
            return result;
        }

    public:
        /**
         * @brief Opens file and calls get().
         * 
         */
        void input() {
            file.open("files\\dataset.txt");
            if (!file) {
                cout << "Error 503 Service Unavailable." << endl;
            }
            else {
                get();
            }

            file.close();

            cout << "Response Code 200 Task Completed Successfully." << endl;
        }


        /**
         * @brief Takes ID and prints the information related to it.
         * 
         * @param ID Required. integer as ID
         */
        void output(int ID) {
            if(1 > ID || ID > 51) {
                cout << "Error 404 Not Found." << endl;
            }
            else {
                cout << endl;
                cout << "----------------------------------------" << endl;
                cout << "ID: " << dataset[ID - 1].ID << endl;
                cout << "DNA: " << dataset[ID - 1].DNA << endl;
                cout << "----------------------------------------" << endl;
            }
        }


        /**
         * @brief Counts the repeated items in an array and manages the information.
         * 
         */
        void count() {
            int counter;


            for(int i = 0; i < 51; i++) {
                for(int j = 0; j < dataset[i].length; j++) {
                    dataset[i].info[j].isChecked = false;
                    dataset[i].info[j].character = dataset[i].DNA[j];
                }
            }

            for(int i = 0; i < 51; i++) {
                for(int j = 0; j < dataset[i].length; j++) {
                    if (!dataset[i].info[j].isChecked) {
                        counter = 0;

                        for(int k = 0; k < dataset[i].length; k++) {
                            if (dataset[i].info[j].character == dataset[i].DNA[k]) {
                                counter++;
                            }
                        }

                        dataset[i].info[j].repeated = counter;
                        dataset[i].info[j].isChecked = true;
                    }
                }
            }

            cout << "Response Code 200 Task Completed Successfully." << endl;
        }


        /**
         * @brief Converts char to ASCII value and manages the information.
         * 
         */
        void convert() {
            for(int i = 0; i < 51; i++) {
                for(int j = 0; j < dataset[i].length; j++) {
                    dataset[i].ascii[j] = int (dataset[i].DNA[j]);
                }
            }

            cout << "Response Code 200 Task Completed Successfully." << endl;
        }


        /**
         * @brief Converts ASCII to binary value and manages the information.
         * 
         */
        void binary() {
            for(int i = 0; i < 51; i++) {
                for(int j = 0; j < dataset[i].length; j++) {
                    bin(dataset[i].binary[j], dataset[i].ascii[j]);
                }
            }

            cout << "Response Code 200 Task Completed Successfully." << endl;
        }


        /**
         * @brief Detects the target.
         * 
         */
        void detect() {
            target = dataset[50];

            cout << "Response Code 200 Task Completed Successfully." << endl;
        }


        /**
         * @brief Compare ASCII values of the target and other information.
         * 
         */
        void compare() {
            int difference;

            for(int i = 0; i < 51; i++) {
                difference = 0;

                for(int j = 0; j < dataset[i].length; j++) {
                    difference += (target.ascii[j] - dataset[i].ascii[j]);
                }

                dataset[i].similarity = difference;
            }

            cout << "Response Code 200 Task Completed Successfully." << endl;
        }


        /**
         * @brief Finds the maximum similarity with target.
         * 
         */
        void search() {
            int min;

            min = dataset[0].similarity;
            for(int i = 0; i < 50; i++) {
                if (dataset[i].similarity < min && dataset[i].similarity > -1) {
                    min = dataset[i].similarity;
                }
            }

            for(int i = 0; i < 50; i++) {
                if (dataset[i].similarity == min) {
                    cout << endl;
                    cout << "ID: " << dataset[i].ID << endl;
                    cout << "DNA: " << dataset[i].DNA << endl;
                    cout << "Similarity: " << dataset[i].similarity << endl;
                    cout << "----------------------------------------" << endl;
                }
            }
        }


        /**
         * @brief Calculates euclidean, manhattan, and minkowski distance.
         * 
         */
        void distance() {
            for(int i = 0; i < 51; i++) {
                dataset[i].interval.euclidiean = euclidean(target.ascii, dataset[i].ascii, 25);
                dataset[i].interval.manhattan = manhattan(target.ascii, dataset[i].ascii, 25);
                dataset[i].interval.minkowski = minkowski(target.ascii, dataset[i].ascii, 25, 3);
            }

            cout << "Response Code 200 Task Completed Successfully." << endl;
        }


        /**
         * @brief Encrypt with caesar cipher algorithm and manages the information.
         * 
         * @param shift Required. integer as shifted value
         */
        void encrypt(int shift) {
            int bridge;
            string cipher;

            for (int i = 0; i < 51; i++) {
                cipher = "0000000000000000000000000";

                for (int j = 0; j < dataset[i].length; j++) {
                    bridge = int (dataset[i].DNA[j]);

                    if (isupper(dataset[i].DNA[j])) {
                        cipher[j] = char (((bridge + shift - 65) % 26) + 65);
                    }
                    else {
                        cipher[j] = char (((bridge + shift - 97) % 26) + 97);
                    }
                }

                dataset[i].shift = shift;
                dataset[i].encrypted = cipher;
            }

            cout << "Response Code 200 Task Completed Successfully." << endl;
        }


        /**
         * @brief Decrypt with caesar cipher algorithm and manages the information.
         * 
         * @param ID 
         */
        void decrypt(int ID) {
            int bridge;
            string plain = "0000000000000000000000000";


            for(int i = 0; i < 51; i++) {
                    for(int j = 0; j < dataset[i].length; j++) {
                        bridge = int (dataset[i].encrypted[j]);

                        if (isupper(dataset[i].DNA[j])) {
                            plain[j] = char (((((bridge - dataset[i].shift - 65) % 26) + 26) % 26) + 65);
                        }
                        else {
                            plain[j] = char (((((bridge - dataset[i].shift - 97) % 26) + 26) % 26) + 97);
                        }
                    }

                    dataset[i].decrypted = plain;
            }

            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "ID: " << dataset[ID - 1].ID << endl;
            cout << "Encryption Key: " << dataset[ID - 1].shift << endl;
            cout << "Encrypted DNA: " << dataset[ID - 1].encrypted << endl;
            cout << "Decrypted DNA: " << dataset[ID - 1].decrypted << endl;
            cout << "----------------------------------------" << endl;
        }


        /**
         * @brief Saves all the information in a file.
         * 
         * @param path Required. path to save the file
         */
        void save(string path) {
            results.open(path);

            if(!results) {
                cout << "Error 503 Service Unavailable." << endl;;
            }
            else {
                for(int i = 0; i < 51; i++) {
                    results << "ID: " << dataset[i].ID << endl;
                    results << "DNA: " << dataset[i].DNA << endl;
                    results << "DNA Sequence Length: " << dataset[i].length << endl;

                    results << endl;
                    results << "DNA Sequence Details: " << endl;
                    for(int j = 0; j < dataset[i].length; j++) {
                        if (dataset[i].info[j].isChecked) {
                            results << dataset[i].info[j].character << " -> " << dataset[i].info[j].repeated << endl;
                        }
                            
                        for(int k = 0; k < dataset[i].length; k++) {
                            if (dataset[i].info[j].character == dataset[i].info[k].character) {
                                dataset[i].info[k].isChecked = false;
                            }
                        }
                    }

                    results << endl;
                    results << "ASCII DNA Sequence: ";
                    for(int j = 0; j < dataset[i].length; j++) {
                        results << dataset[i].ascii[j] << " ";
                    }
                    results << endl;

                    results << endl;
                    results << "Binary DNA Sequence: ";
                    for(int j = 0; j < dataset[i].length; j++) {
                        for(int k = 0; k < 7; k++) {
                            results << dataset[i].binary[j][k];
                        }

                        results << " ";
                    }
                    results << endl;

                    results << endl;
                    results << "Target DNA Similarity: " << dataset[i].similarity << endl;

                    results << endl;
                    results << "Target DNA Distance: " << endl;
                    results << "\tEuclidean Distance: " << dataset[i].interval.euclidiean << endl;
                    results << "\tManhattan Distance: " << dataset[i].interval.manhattan << endl;
                    results << "\tMinkowski Distance: " << dataset[i].interval.minkowski << endl;

                    results << endl;
                    results << "Cipher Shift Key: " << dataset[i].shift << endl;

                    results << endl;
                    results << "Encrypted DNA Sequence: " << dataset[i].encrypted << endl;

                    results << endl;
                    results << "Decrypted DNA Sequence: " << dataset[i].decrypted << endl;
                    results << "--------------------------------------------------\n" << endl; 
                }
            }

            results.close();
            cout << "Response Code 200 Task Completed Successfully." << endl;
        }


        /**
         * @brief Handles the interactions with the user.
         * 
         */
        void launcher() {
            int ID;
            int shift;
            int function;
            string path;

            cout << "----------------------------------------" << endl;
            cout << "----------- Welcome to Dinder ----------" << endl;
            cout << "----------------------------------------" << endl;

            while(true) {
                print();
                cin >> function;

                if (function == 1) {
                    input();
                }
                else if (function == 2) {
                    cout << "ID: ";
                    cin >> ID;

                    output(ID);
                }
                else if (function == 3) {
                    count();
                }
                else if (function == 4) {
                    convert();
                }
                else if (function == 5) {
                    binary();
                }
                else if (function == 6) {
                    detect();
                }
                else if (function == 7) {
                    compare();
                }
                else if (function == 8) {
                    search();
                }
                else if (function == 9) {
                    distance();
                }
                else if (function == 10) {
                    shift = 5;

                    encrypt(shift);
                }
                else if (function == 11) {
                    cout << "ID: ";
                    cin >> ID;

                    decrypt(ID);
                }
                else if (function == 12) {
                    path = "results\\results.txt";

                    save(path);
                }
                else if (function == 13) {
                    break;
                }
                else {
                    cout << "Error 400 Bad Request." << endl;
                }    
            }
        }
};

int main() {
    App app;


    app.launcher();

    return 0;
}