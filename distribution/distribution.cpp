#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

struct Character {
    int type;
    int race;
    set <pair<string, string>> attributes;

    Character(int type, int race) {
        this->type = type;
        this->race = race;
    }
};

std::random_device rd;
std::mt19937 gen(rd());

vector <Character> initial;
vector <Character> result;

const int MEN_EURO = 1885;
const int MEN_AFRO = 1884;
const int MEN_ASIAN = 1885;

const int WOMEN_EURO = 1107;
const int WOMEN_AFRO = 1106;
const int WOMEN_ASIAN = 1107;

// adolescent is given as an attribute

const int CHILDREN_EURO_MEN = 134;
const int CHILDREN_EURO_WOMEN = 133;

const int CHILDREN_AFRO_MEN = 133;
const int CHILDREN_AFRO_WOMEN = 133;

const int CHILDREN_ASIAN_MEN = 134;
const int CHILDREN_ASIAN_WOMEN = 133;

const int BEARS_NUM = 80;
const int MUZZLE_NUM = 50;

const int LEGENDARY_NUM = 13;
const int LEGENDARY_RESERVE = 6;

// 1 - man
// 2 - woman
// 3 - bear
// 4 - muzzle

const int TWO = 30;
const int THREE = 250;
const int FOUR = 2526;
const int FIVE = 4128;
const int SIX = 2092;
const int SEVEN = 891;

vector <pair<pair<pair<string, string>, set<int>>, int>> clothes = {
    {{{"Clothes", "Apron"}, {2, 4}}, 1},
    {{{"Clothes", "Boy school uniform"}, {1, 3, 4}}, 3},
    {{{"Clothes", "Commisar's jacket"}, {1, 2, 3, 4}}, 5},
    {{{"Clothes", "Dress suit"}, {1, 3, 4}}, 4},
    {{{"Clothes", "Embroidered shirt"}, {2}}, 4},
    {{{"Clothes", "Felt cloak"}, {1, 2, 3, 4}}, 5},
    {{{"Clothes", "Fidenza overall"}, {1, 2, 3, 4}}, 9},
    {{{"Clothes", "Fur coat"}, {2}}, 5},
    {{{"Clothes", "Girl school uniform"}, {2, 3}}, 3},
    {{{"Clothes", "Greatcoat"}, {1, 2, 3, 4}}, 5},
    {{{"Clothes", "Joker suit Hoaken"}, {1, 2, 3, 4}}, 7},
    {{{"Clothes", "Joker suit Ledger"}, {1, 2, 3, 4}}, 7},
    {{{"Clothes", "Man coat"}, {1, 3, 4}}, 3},
    {{{"Clothes", "Overall"}, {1, 2, 3, 4}}, 1},
    {{{"Clothes", "Sport suit"}, {1, 2, 3, 4}}, 1},
    {{{"Clothes", "Tunic"}, {1, 3, 4}}, 1},
    {{{"Clothes", "Woman coat"}, {2}}, 3},
    {{{"Clothes", "Work apron"}, {1, 2, 3, 4}}, 3},
};

vector <pair<pair<pair<string, string>, set<int>>, int>> rightHand = {
    {{{"Right hand", "Atom poster"}, {1, 2, 3, 4}}, 3},
    {{{"Right hand", "AK47"}, {1, 2, 3, 4}}, 6},
    {{{"Right hand", "Axe"}, {1, 2, 3, 4}}, 1},
    {{{"Right hand", "Balalaika"}, {1, 2, 3, 4}}, 3},
    {{{"Right hand", "Buggle"}, {1, 2, 3, 4}}, 5},
    {{{"Right hand", "Golden hammer"}, {1, 2, 3, 4}}, 8},
    {{{"Right hand", "Golden sickle"}, {1, 2, 3, 4}}, 8},
    {{{"Right hand", "Golden telephone"}, {1, 2, 3, 4}}, 8},
    {{{"Right hand", "Hammer"}, {1, 2, 3, 4}}, 3},
    {{{"Right hand", "Iphone"}, {1, 2, 3, 4}}, 5},
    {{{"Right hand", "Jackhammer"}, {1, 2, 3, 4}}, 7},
    {{{"Right hand", "Kettlebell"}, {1, 2, 3, 4}}, 1},
    {{{"Right hand", "Leaflet"}, {1, 2, 3, 4}}, 1},
    {{{"Right hand", "Pink gun"}, {1, 2, 3, 4}}, 5},
    {{{"Right hand", "Pitchfork"}, {1, 2, 3, 4}}, 3},
    {{{"Right hand", "PPSh"}, {1, 2, 3, 4}}, 4},
    {{{"Right hand", "Revolver"}, {1, 2, 3, 4}}, 4},
    {{{"Right hand", "Rifle"}, {1, 2, 3, 4}}, 4},
    {{{"Right hand", "Rolled newspaper"}, {1, 2, 3, 4}}, 1},
    {{{"Right hand", "Saber"}, {1, 2, 3, 4}}, 6},
    {{{"Right hand", "Schmeisser"}, {1, 2, 3, 4}}, 4},
    {{{"Right hand", "Scythe"}, {1, 2, 3, 4}}, 3},
    {{{"Right hand", "Sheaf"}, {1, 2, 3, 4}}, 4},
    {{{"Right hand", "Sickle"}, {1, 2, 3, 4}}, 3},
    {{{"Right hand", "Space poster"}, {1, 2, 3, 4}}, 3},
    {{{"Right hand", "Surfboard"}, {1, 2, 3, 4}}, 5},
    {{{"Right hand", "Surfboard with leaders"}, {1, 2, 3, 4}}, 7},
    {{{"Right hand", "Telephone"}, {1, 2, 3, 4}}, 3},
    {{{"Right hand", "Trowel"}, {1, 2, 3, 4}}, 1},
    {{{"Right hand", "Wrench"}, {1, 2, 3, 4}}, 3},
    {{{"Right hand", "Diamond Bugle"}, {1, 2, 3, 4}}, 8},
    {{{"Right hand", "Diamond First poster"}, {1, 2, 3, 4}}, 8},
    {{{"Right hand", "Diamond Golden hammer"}, {1, 2, 3, 4}}, 9},
    {{{"Right hand", "Diamond Golden sickle"}, {1, 2, 3, 4}}, 9},
    {{{"Right hand", "Diamond Golden telephone"}, {1, 2, 3, 4}}, 8},
    {{{"Right hand", "Diamond Iphone"}, {1, 2, 3, 4}}, 9},
    {{{"Right hand", "Diamond Pink gun"}, {1, 2, 3, 4}}, 9},
    {{{"Right hand", "Diamond PPSh"}, {1, 2, 3, 4}}, 8},
    {{{"Right hand", "Diamond Rifle"}, {1, 2, 3, 4}}, 8},
    {{{"Right hand", "Diamond Sheaf"}, {1, 2, 3, 4}}, 9},
    {{{"Right hand", "Diamond Surfboard with leaders"}, {1, 2, 3, 4}}, 9},
    {{{"Right hand", "Diamond АК47"}, {1, 2, 3, 4}}, 9},
};

vector <pair<pair<pair<string, string>, set<int>>, int>> leftHand = {
    {{{"Left hand", "Beeple newspaper"}, {1, 2, 3, 4}}, 3},
    {{{"Left hand", "Cap shield"}, {1, 2, 3, 4}}, 7},
    {{{"Left hand", "Chapaev"}, {1, 2, 3, 4}}, 3},
    {{{"Left hand", "Choi guitar"}, {1, 2, 3, 4}}, 5},
    {{{"Left hand", "Das kapital"}, {1, 2, 3, 4}}, 3},
    {{{"Left hand", "Dumbbell"}, {1, 2, 3, 4}}, 1},
    {{{"Left hand", "Glass holder"}, {1, 2, 3, 4}}, 3},
    {{{"Left hand", "Glass"}, {1, 2, 3, 4}}, 1},
    {{{"Left hand", "Glass with vodka"}, {1, 2, 3, 4}}, 3},
    {{{"Left hand", "Golden das kapital"}, {1, 2, 3, 4}}, 8},
    {{{"Left hand", "Golden dumbbell"}, {1, 2, 3, 4}}, 8},
    {{{"Left hand", "Golden glass holder"}, {1, 2, 3, 4}}, 8},
    {{{"Left hand", "Guitar"}, {1, 2, 3, 4}}, 3},
    {{{"Left hand", "International"}, {1, 2, 3, 4}}, 3},
    {{{"Left hand", "Kobzar"}, {1, 2, 3, 4}}, 5},
    {{{"Left hand", "Mayakovsky"}, {1, 2, 3, 4}}, 3},
    {{{"Left hand", "Nalivka"}, {1, 2, 3, 4}}, 1},
    {{{"Left hand", "Red balloon"}, {1, 2, 3, 4}}, 1},
    {{{"Left hand", "Redblock newspaper"}, {1, 2, 3, 4}}, 3},
    {{{"Left hand", "Russian sausage"}, {1, 2, 3, 4}}, 1},
    {{{"Left hand", "Sausage"}, {1, 2, 3, 4}}, 1},
    {{{"Left hand", "Taperecorder"}, {1, 2, 3, 4}}, 6},
    {{{"Left hand", "Vodka"}, {1, 2, 3, 4}}, 5},
    {{{"Left hand", "White balloon"}, {1, 2, 3, 4}}, 1},
    {{{"Left hand", "Diamond Choi guitar"}, {1, 2, 3, 4}}, 8},
    {{{"Left hand", "Diamond Das kapital"}, {1, 2, 3, 4}}, 8},
    {{{"Left hand", "Diamond Golden dumbbell"}, {1, 2, 3, 4}}, 9},
    {{{"Left hand", "Diamond Golden glass holder"}, {1, 2, 3, 4}}, 9},
    {{{"Left hand", "Diamond Kobzar"}, {1, 2, 3, 4}}, 9},
    {{{"Left hand", "Diamond Taperecorder"}, {1, 2, 3, 4}}, 9},
    {{{"Left hand", "Diamond Vodka"}, {1, 2, 3, 4}}, 9},
};

vector <pair<pair<pair<string, string>, set<int>>, int>> headdress = {
    {{{"Headdress", "Batman ushanka"}, {3, 4}}, 6},
    {{{"Headdress", "Black bandana"}, {1, 2, 3, 4}}, 1},
    {{{"Headdress", "Blue peaked cap"}, {1, 2, 3, 4}}, 3},
    {{{"Headdress", "Budenovka"}, {1, 2, 3, 4}}, 3},
    {{{"Headdress", "Dandelion wreath"}, {1, 2, 3, 4}}, 1},
    {{{"Headdress", "Flight helmet"}, {1, 2, 3, 4}}, 3},
    {{{"Headdress", "Green peaked cap"}, {1, 2, 3, 4}}, 3},
    {{{"Headdress", "Lenin's cap"}, {1, 2, 3, 4}}, 8},
    {{{"Headdress", "Motorcycle helmet"}, {1, 2, 3, 4}}, 3},
    {{{"Headdress", "Papakha"}, {1, 2, 4}}, 6},
    {{{"Headdress", "Peakless cap"}, {1, 2, 3, 4}}, 5},
    {{{"Headdress", "Red bandana"}, {1, 2, 3, 4}}, 1},
    {{{"Headdress", "Tank helmet"}, {1, 2, 4}}, 5},
    {{{"Headdress", "Ushanka"}, {1, 2, 3, 4}}, 7},
    {{{"Headdress", "White bandana"}, {1, 2, 3, 4}}, 1},
};

vector <pair<pair<pair<string, string>, set<int>>, int>> face = {
    {{{"Face", "3D glasses"}, {1, 2}}, 3},
    {{{"Face", "Bitcoin earrings"}, {2, 4}}, 5},
    {{{"Face", "Blush 1"}, {1, 2}}, 1},
    {{{"Face", "Blush 2"}, {1, 2}}, 1},
    {{{"Face", "Chapaev mustache"}, {1}}, 5},
    {{{"Face", "Cigarette"}, {1, 2}}, 3},
    {{{"Face", "Dali mustache"}, {1}}, 7},
    {{{"Face", "Earrings"}, {2, 4}}, 3},
    {{{"Face", "Glasses"}, {1, 2}}, 3},
    {{{"Face", "Goatee"}, {1}}, 5},
    {{{"Face", "Green spica"}, {1, 2}}, 1},
    {{{"Face", "Matrix glasses"}, {1, 2}}, 7},
    {{{"Face", "Stalin pipe"}, {1, 2}}, 8},
    {{{"Face", "VR headset"}, {1, 2, 4}}, 7},
    {{{"Face", "Yellow spica"}, {1, 2}}, 1},
};

vector <pair<pair<pair<string, string>, set<int>>, int>> decoration = {
    {{{"Decoration", "Cheburashka olympiad badge"}, {1, 2, 3, 4}}, 7},
    {{{"Decoration", "Congress badge"}, {1, 2, 3, 4}}, 3},
    {{{"Decoration", "Cosmos badge"}, {1, 2, 3, 4}}, 3},
    {{{"Decoration", "Doge badge"}, {1, 2, 3, 4}}, 1},
    {{{"Decoration", "First olympiad medal"}, {1, 2, 3, 4}}, 7},
    {{{"Decoration", "First Suvorov badge"}, {1, 2, 3, 4}}, 7},
    {{{"Decoration", "Fourth olympiad badge"}, {1, 2, 3, 4}}, 3},
    {{{"Decoration", "Friendship of nations medal"}, {1, 2, 3, 4}}, 7},
    {{{"Decoration", "Laborand valor medal"}, {1, 2, 3, 4}}, 5},
    {{{"Decoration", "Lenin medal"}, {1, 2, 3, 4}}, 9},
    {{{"Decoration", "Medal"}, {1, 2, 3, 4}}, 1},
    {{{"Decoration", "Moon badge"}, {1, 2, 3, 4}}, 3},
    {{{"Decoration", "Nyan cat badge"}, {1, 2, 3, 4}}, 1},
    {{{"Decoration", "Octobrist badge"}, {1, 2, 3, 4}}, 5},
    {{{"Decoration", "Pioneer badge"}, {1, 2, 3, 4}}, 5},
    {{{"Decoration", "Pioneer tie"}, {1, 2, 3, 4}}, 3},
    {{{"Decoration", "Red bow"}, {1, 2, 3, 4}}, 1},
    {{{"Decoration", "Red star medal"}, {1, 2, 3, 4}}, 9},
    {{{"Decoration", "Revolution medal"}, {1, 2, 3, 4}}, 5},
    {{{"Decoration", "Second olympiad medal"}, {1, 2, 3, 4}}, 5},
    {{{"Decoration", "Second Suvorov badge"}, {1, 2, 3, 4}}, 5},
    {{{"Decoration", "Shiba badge"}, {1, 2, 3, 4}}, 1},
    {{{"Decoration", "Third olympiad badge"}, {1, 2, 3, 4}}, 5},
    {{{"Decoration", "Third Suvorov badge"}, {1, 2, 3, 4}}, 3},
    {{{"Decoration", "Vigilante badge"}, {1, 2, 3, 4}}, 3},
    {{{"Decoration", "VLKSM badge"}, {1, 2, 3, 4}}, 5},
    {{{"Decoration", "Young tourist badge"}, {1, 2, 3, 4}}, 1},
};

vector <pair<pair<pair<string, string>, set<int>>, int>> flag = {
    {{{"Flag", "Bulgaria"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "Cambodia"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "China"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "Cuba"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "Czechoslovakia"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "GDR"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "Hengary"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "Laos"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "LGBT"}, {1, 2, 3, 4}}, 4},
    {{{"Flag", "North Korea"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "Poland"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "Romania"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "USSR"}, {1, 2, 3, 4}}, 6},
    {{{"Flag", "Vietnam"}, {1, 2, 3, 4}}, 1},
    {{{"Flag", "Yugoslavia"}, {1, 2, 3, 4}}, 1},
};

vector <pair<pair<pair<string, string>, set<int>>, int>> background = {
    {{{"Background", "Armored car"}, {1, 2, 3, 4}}, 5},
    {{{"Background", "Bath house"}, {1, 2, 3, 4}}, 4},
    {{{"Background", "Birch grove north"}, {1, 2, 3, 4}}, 2},
    {{{"Background", "Birch grove south"}, {1, 2, 3, 4}}, 2},
    {{{"Background", "Corn field"}, {1, 2, 3, 4}}, 5},
    {{{"Background", "Cruiser Aurora"}, {1, 2, 3, 4}}, 7},
    {{{"Background", "Factory"}, {1, 2, 3, 4}}, 5},
    {{{"Background", "Field dawn"}, {1, 2, 3, 4}}, 1},
    {{{"Background", "Field day"}, {1, 2, 3, 4}}, 1},
    {{{"Background", "Field dusk"}, {1, 2, 3, 4}}, 1},
    {{{"Background", "Kremlin"}, {1, 2, 3, 4}}, 8},
    {{{"Background", "Parlor beige"}, {1, 2, 3, 4}}, 2},
    {{{"Background", "Parlor white"}, {1, 2, 3, 4}}, 2},
};

int randomNum(int left, int right) {
    std::uniform_int_distribution<> distr(left, right - 1);

    return distr(gen);
}

int getQuantity(int rarity) {
    return max(int(100 - rarity * rarity * 1.2), 3);
}

void applyRaritiesTo(vector <pair<pair<pair<string, string>, set<int>>, int>>& in) {
    vector <pair<pair<pair<string, string>, set<int>>, int>> out;

    for (int i = 0; i < in.size(); i++) {
        int howMany = getQuantity(in[i].second);

        for (int j = 0; j < howMany; j++) {
            out.push_back(in[i]);
        }
    }

    in = out;
}

void applyRarities() {
    applyRaritiesTo(clothes);
    applyRaritiesTo(rightHand);
    applyRaritiesTo(leftHand);
    applyRaritiesTo(headdress);
    applyRaritiesTo(flag);
    applyRaritiesTo(decoration);
    applyRaritiesTo(face);
    applyRaritiesTo(background);
}

void fillInCharacters() {
    auto fillIn = [](int num, int type, int race = 0, bool adolescent = false, bool legendary = false) { 
        for (int i = 0; i < num; i++) {
            Character character = Character(type, race);

            if (adolescent) {
                character.attributes.insert({"Appearance", "Adolescent"});
            }            

            if (legendary) {
                character.attributes.insert({"Appearance", "Legendary"});
            }

            initial.push_back(character);
        }
    };

    fillIn(MEN_EURO, 1, 1);
    fillIn(MEN_AFRO, 1, 2);
    fillIn(MEN_ASIAN, 1, 3);

    fillIn(WOMEN_EURO, 2, 1);
    fillIn(WOMEN_AFRO, 2, 2);
    fillIn(WOMEN_ASIAN, 2, 3);

    fillIn(CHILDREN_EURO_MEN, 1, 1, true);
    fillIn(CHILDREN_AFRO_MEN, 1, 2, true);
    fillIn(CHILDREN_ASIAN_MEN, 1, 3, true);

    fillIn(CHILDREN_EURO_WOMEN, 2, 1, true);
    fillIn(CHILDREN_AFRO_WOMEN, 2, 2, true);
    fillIn(CHILDREN_ASIAN_WOMEN, 2, 3, true);

    fillIn(BEARS_NUM, 3);

    fillIn(MUZZLE_NUM, 4);

    fillIn(LEGENDARY_NUM - LEGENDARY_RESERVE, 1, 1, false, true);
}

void findAndInsert(Character& character, vector <pair<pair<pair<string, string>, set<int>>, int>> &vec) {
    while (true) {
        int attrId = randomNum(0, vec.size());

        if (vec[attrId].first.second.find(character.type) != vec[attrId].first.second.end()) {
            character.attributes.insert(vec[attrId].first.first);
            return;
        }
    }
}

void distributeTwo() {
    for (int i = 0; i < TWO; i++) {
        Character character = initial[initial.size() - 1];

        findAndInsert(character, clothes);
        findAndInsert(character, background);

        result.push_back(character);
        initial.pop_back();
    }
}

void distributeThree() {
    for (int i = 0; i < THREE; i++) {
        Character character = initial[initial.size() - 1];

        findAndInsert(character, clothes);
        findAndInsert(character, rightHand);
        findAndInsert(character, background);

        result.push_back(character);
        initial.pop_back();
    }
}

void distributeFour() {
    vector <pair<pair<pair<string, string>, set<int>>, int>> rightOrLeft;
    vector <pair<pair<pair<string, string>, set<int>>, int>> headdressOrFace;

    rightOrLeft.insert(rightOrLeft.end(), rightHand.begin(), rightHand.end());
    rightOrLeft.insert(rightOrLeft.end(), leftHand.begin(), leftHand.end());

    headdressOrFace.insert(headdressOrFace.end(), headdress.begin(), headdress.end());
    headdressOrFace.insert(headdressOrFace.end(), face.begin(), face.end());

    for (int i = 0; i < FOUR; i++) {        
        Character character = initial[initial.size() - 1];

        findAndInsert(character, clothes);
        findAndInsert(character, rightOrLeft);
        findAndInsert(character, headdressOrFace);
        findAndInsert(character, background);

        result.push_back(character);
        initial.pop_back();
    }
}

void distributeFive() {
    vector <pair<pair<pair<string, string>, set<int>>, int>> rightOrLeft;
    vector <pair<pair<pair<string, string>, set<int>>, int>> headdressOrFace;

    rightOrLeft.insert(rightOrLeft.end(), rightHand.begin(), rightHand.end());
    rightOrLeft.insert(rightOrLeft.end(), leftHand.begin(), leftHand.end());

    headdressOrFace.insert(headdressOrFace.end(), headdress.begin(), headdress.end());
    headdressOrFace.insert(headdressOrFace.end(), face.begin(), face.end());

    for (int i = 0; i < FIVE; i++) {
        Character character = initial[initial.size() - 1];

        findAndInsert(character, clothes);
        findAndInsert(character, rightOrLeft);
        findAndInsert(character, headdressOrFace);
        findAndInsert(character, decoration);
        findAndInsert(character, background);

        result.push_back(character);
        initial.pop_back();
    }
}

void distributeSix() {
    vector <pair<pair<pair<string, string>, set<int>>, int>> headdressOrFace;
    
    headdressOrFace.insert(headdressOrFace.end(), headdress.begin(), headdress.end());
    headdressOrFace.insert(headdressOrFace.end(), face.begin(), face.end());

    for (int i = 0; i < SIX; i++) {
        Character character = initial[initial.size() - 1];

        findAndInsert(character, clothes);
        findAndInsert(character, rightHand);
        findAndInsert(character, leftHand);
        findAndInsert(character, headdressOrFace);
        findAndInsert(character, decoration);
        findAndInsert(character, background);

        result.push_back(character);
        initial.pop_back();
    }
}

void distributeSeven() {
    vector <pair<pair<pair<string, string>, set<int>>, int>> headdressOrFace;

    headdressOrFace.insert(headdressOrFace.end(), headdress.begin(), headdress.end());
    headdressOrFace.insert(headdressOrFace.end(), face.begin(), face.end());

    for (int i = 0; i < SEVEN - LEGENDARY_RESERVE; i++) {
        Character character = initial[initial.size() - 1];
        
        findAndInsert(character, clothes);
        findAndInsert(character, flag);
        findAndInsert(character, rightHand);
        findAndInsert(character, leftHand);
        findAndInsert(character, headdressOrFace);
        findAndInsert(character, decoration);
        findAndInsert(character, background);

        result.push_back(character);
        initial.pop_back();
    }
}

void cleanUp() {
    shuffle(result.begin(), result.end(), gen);

    for (int i = 0; i < LEGENDARY_RESERVE; i++) {
        Character character = Character(0, 0);
        character.attributes.insert({ "Appearance", "Legendary" });

        result.push_back(character);
    }

    reverse(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) {
        set<pair<string, string>> attributes = result[i].attributes;

        bool left = false;
        bool right = false;

        if (attributes.find({"Appearance", "Legendary"}) != attributes.end()) {
            attributes.clear();
            attributes.insert({"Appearance", "Legendary"});
        } else {
            for (auto i : result[i].attributes) {
                if (i.second.find("Diamond") != string::npos) {
                    if (i.first == "Right hand") {
                        right = true;
                    } else if (i.first == "Left hand") {
                        left = true;
                    }

                    attributes.erase(i);
                    attributes.insert({ i.first, i.second.substr(8) });
                }
            }

            if (left && right) {
                attributes.insert({ "Diamond hands", "Both" });
            } else if (left) {
                attributes.insert({ "Diamond hands", "Left" });
            } else if (right) {
                attributes.insert({ "Diamond hands", "Right" });
            }
        }

        result[i].attributes = attributes;
    }
}

void distribute() {
    shuffle(initial.begin(), initial.end(), gen);

    distributeTwo();    
    distributeThree();    
    distributeFour();    
    distributeFive(); 
    distributeSix();
    distributeSeven();

    cleanUp();
}

void print() {
    // ostream &out = cout;

    for (int i = 0; i < result.size(); i++) {
        Character &character = result[i];

        ofstream out("./distribution_jsons/" + to_string(i + 1) + ".json");

        out << "{\n";

        out << "\t\"attributes\": [\n";

        if (character.attributes.find({ "Appearance", "Legendary" }) == character.attributes.end()) {
            if (character.type) {
                string charact;

                if (character.type == 1) {
                    charact = "Man";
                } else if (character.type == 2) {
                    charact = "Woman";
                } else if (character.type == 3) {
                    charact = "Bear";
                } else if (character.type == 4) {
                    charact = "Muzzle";
                }

                out << "\t\t{ \"trait_type\": \"Character\", \"value\": \"" + charact + "\" },\n";
            }

            if (character.race) {
                string race = "";

                if (character.race == 1) {
                    race = "European";
                } else if (character.race == 2) {
                    race = "Afro-American";
                } else if (character.race == 3) {
                    race = "Asian";
                }

                out << "\t\t{ \"trait_type\": \"Race\", \"value\": \"" + race + "\" },\n";
            }   
        }

        int index = 0;

        for (auto& j : character.attributes) {
            out << "\t\t{ \"trait_type\": \"" + j.first + "\", \"value\": \"" + j.second + "\" }";

            if (index < character.attributes.size() - 1) {
                out << ",\n";
            } else {
                out << "\n";
            }

            index++;
        }

        out << "\t],\n";

        out << "\t\"description\": \"We are 9917 unique NFTs on Ethereum blockchain. Redblock Сomrades are inspired by the Soviet Union's dream to unite all the workers of the world. Join our digital commune!\",\n";
        out << "\t\"external_url\": \"https://redblock.digital/\",\n";
        out << "\t\"image\": \"\",\n";
        out << "\t\"name\": \"Redblock Comrade #" + to_string(i + 1) + "\"\n";

        out << "}\n";
    }
}

int main() {
    fillInCharacters();
    applyRarities();
    distribute();
    print();

    return 0;
}