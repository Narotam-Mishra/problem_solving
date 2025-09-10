
// Problem link - https://leetcode.com/problems/minimum-number-of-people-to-teach/description/?envType=daily-question&envId=2025-09-10

let minimumTeachings = function(n, languages, friendships) {
    // `sadUsers` are users who can't communicate with at least one friend
    const sadUsers = new Set();    

    // step - 1 : identify all problematic friendships and collect sad users
    for(const friends of friendships){
        // convert this to 0-based indexing
        let u = friends[0] - 1;
        let v = friends[1] - 1;

        // step 2 - create a set of languages known by user `u`
        const langSetU = new Set(languages[u]);

        // step 3 - check if users u and v can communicate (share any common language)
        let canTalk = false;
        for(const lang of languages[v]){
            if(langSetU.has(lang)){
                // found common language
                canTalk = true;
                break;
            }
        }

        // step 4 - if they can't talk then they are sad users
        if(!canTalk){
            sadUsers.add(u);
            sadUsers.add(v);
        }
    }

    // step 5 - find the language that is already known by most sad users
    // array to count how many sad users know each language
    const languageCount = new Array(n+1).fill(0);
    let mostKnownLang = 0;

    // step 6 - count language knowledge among sad users only
    for(const user of sadUsers){
        for(const lang of languages[user]){
            languageCount[lang]++;
            mostKnownLang = Math.max(mostKnownLang, languageCount[lang]);
        }
    }

    // step 7 - calculate minimum teachings needed and return
    // if we teach the most popular language among sad users,
    // we need to teach (total sad users - users who already know that language)
    return sadUsers.size - mostKnownLang;
};

// const n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]];

const n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]];
console.log(minimumTeachings(n, languages, friendships));