const sharp = require("sharp");
const fs = require("fs");

const jsonsDir = "./distribution/distribution_jsons/";

function getRandomInt(max) {
    return Math.floor(Math.random() * max);
}

function getHeadPath(attributes) {
    let headPath = "./redblock-dataset/Head/";

    let legendary = false;
    let adolescent = false;
    let character = "";
    let race = "";

    for (let i = 0; i < attributes.length; i++) {
        let attribute = attributes[i];

        if (attribute["trait_type"] == "Appearance") {
            if (attribute["value"] == "Legendary") {
                legendary = true;
                break;
            } else if (attribute["value"] == "Adolescent") {
                adolescent = true;
            }
        }

        if (attribute["trait_type"] == "Character") {
            character = attribute["value"];
        }

        if (attribute["trait_type"] == "Race") {
            race = attribute["value"];
        }
    }

    if (legendary) {
        return "";
    }

    if (character == "Bear" || character == "Muzzle") {
        return headPath + character + "/1.png";
    }

    if (adolescent) {
        return headPath + "Adolescent/" + race + "/" + character + "/1.png";
    }

    return headPath + character + "/" + race + "/" + (getRandomInt(2) + 1) + ".png";
}

function getAttributePath(attributes, which) {
    let path = "./redblock-dataset/" + which + "/";

    for (let i = 0; i < attributes.length; i++) {
        let attribute = attributes[i];

        if (attribute["trait_type"] == which) {
            let attr = String(attribute["value"])
                .replace(" ", "-")
                .replace(" ", "-")
                .replace(" ", "-");

            return path + attr + ".png";
        }
    }

    return "";
}

function getHandPath(attributes, hand) {
    let path = "./redblock-dataset/" + hand + "/";

    let handPath = "Empty.png";
    let color = "";

    for (let i = 0; i < attributes.length; i++) {
        let attribute = attributes[i];

        if (
            String(attribute["trait_type"])
                .replace(" ", "-")
                .replace(" ", "-")
                .replace(" ", "-") == hand
        ) {
            let attr = String(attribute["value"])
                .replace(" ", "-")
                .replace(" ", "-")
                .replace(" ", "-");

            handPath = attr + ".png";
        }

        if (
            attribute["trait_type"] == "Character" &&
            color == ""
        ) {
            if (attribute["value"] == "Bear") {
                color = "Afro-American";
            } else if (attribute["value"] == "Muzzle") {  
                color = "European";      
            }
        }

        if (attribute["trait_type"] == "Race" && color == "") {
            color = attribute["value"];
        }

        if (attribute["trait_type"] == "Diamond hands") {
            if (
                attribute["value"] == "Both" ||
                attribute["value"] == hand.substring(0, hand.indexOf("-"))
            ) {
                color = "Diamond-hands";
            }
        }
    }

    return path + color + "/" + handPath;
}

function getLeftHandPath(attributes) {
    return getHandPath(attributes, "Left-hand");
}

function getRightHandPath(attributes) {
    return getHandPath(attributes, "Right-hand");
}

function getClothesPath(attributes) {
    return getAttributePath(attributes, "Clothes");
}

function getDecorationPath(attributes) {
    return getAttributePath(attributes, "Decoration");
}

function getFacePath(attributes) {
    return getAttributePath(attributes, "Face");
}

function getFlagPath(attributes) {
    return getAttributePath(attributes, "Flag");
}

function getBackgroundPath(attributes) {
    return getAttributePath(attributes, "Background");
}

function getHeaddressPath(attributes) {
    return getAttributePath(attributes, "Headdress");
}

function compile(
    headPath,
    clothesPath,
    decorationPath,
    facePath,
    flagPath,
    backgroundPath,
    headdressPath,
    leftHandPath,
    rightHandPath,
    index
) {
    try {
        let outputPath = "./generation/generation-images/";

        let images = [
            {
                input: flagPath,
            },
            {
                input: headPath,
            },
            {
                input: clothesPath,
            },
            {
                input: facePath,
            },
            {
                input: decorationPath,
            },
            {
                input: rightHandPath,
            },
            {
                input: leftHandPath,
            },
            {
                input: headdressPath,
            },
        ];

        images = images.filter((el) => el.input != "");

        // console.log(images);

        let compositedImage = sharp(backgroundPath).composite(images);
        compositedImage.toFile(outputPath + index + ".png");
    } catch (e) {
        console.log(e);
    }
}

for (let i = 0; i < 100; i++) {
    const fileContents = fs.readFileSync(jsonsDir + (i + 1) + ".json", "utf8");

    try {
        const data = JSON.parse(fileContents);
        const attributes = data["attributes"];

        let headPath = getHeadPath(attributes);

        if (headPath == "") {
            console.log("Legendary " + (i + 1));
            continue;
        }

        let clothesPath = getClothesPath(attributes);
        let decorationPath = getDecorationPath(attributes);
        let facePath = getFacePath(attributes);
        let flagPath = getFlagPath(attributes);
        let backgroundPath = getBackgroundPath(attributes);
        let headdressPath = getHeaddressPath(attributes);
        let leftHandPath = getLeftHandPath(attributes);
        let rightHandPath = getRightHandPath(attributes);

        compile(
            headPath,
            clothesPath,
            decorationPath,
            facePath,
            flagPath,
            backgroundPath,
            headdressPath,
            leftHandPath,
            rightHandPath,
            i + 1
        );
    } catch (err) {
        console.error(err);
    }
}
