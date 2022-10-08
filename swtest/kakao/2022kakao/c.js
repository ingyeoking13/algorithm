let insdAnswer = 0;
let buyAnswer = 0;
let stateAnswer;
const visited = new Set()

function goFind(users, emoticons, state, rates) {
    const d = state.map(String).join(',')
    if(visited.has(d)) return;
    visited.add(d);

    let insdCount = 0;
    let buyPayment = 0;
    for (user of users){
        let payment = 0;
        const userLikeRate = user[0];
        const userThreadsHold = user[1];
        for (let i =0; i<emoticons.length; i++){
            if (userLikeRate > state[i] ) continue;
            const bill = emoticons[i]*(100-state[i])/100
            payment += bill;
        }
        if (payment >= userThreadsHold) {
            insdCount++;
        } 
        else buyPayment += payment;
    }

    if (insdCount > insdAnswer) {
        insdAnswer = insdCount; 
        buyAnswer = buyPayment
        stateAnswer = state;
    }

    if (insdCount == insdAnswer && buyPayment >= buyAnswer) {
        buyAnswer = buyPayment;
        stateAnswer = state;
    }

    for (let i=0; i<state.length; i++) {
        const curRate = state[i]; 
        const index = rates.findIndex(rate => rate==curRate);
        if (index == rates.length-1) continue;
        let nextIndex = index+1;
        while(true){
            if (nextIndex == rates.length ) break;
            const nextRate = rates[nextIndex];
            const nextState = [...state];
            nextState[i] = nextRate;
            goFind(users, emoticons, nextState, rates);
            if (++nextIndex == rates.length) {
                break;
            }
        }
    }
}

function solution(users, emoticons) {
  var answer = [];
  rates = [...new Set(users.map(a=>a[0]).sort((a, b)=> b-a))]
  // 모든 사용자가 구매했을 때의 가격 
  const initialState = Array(emoticons.length).fill(10)
  goFind(users, emoticons, initialState, [10, 20, 30, 40]);
  console.log(insdAnswer, buyAnswer, stateAnswer);
  return [insdAnswer, buyAnswer];
}

solution( 
    [ [40, 10000], [25, 10000], ], 
    [7000, 9000] 
);

solution( 
    [ [40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900] ], 
    [1300, 1500, 1600, 4900]
);


function test(users, emoticons, state) {
    // const users = [[40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900]] 
    // const state = [5, 11, 40 , 40];
    // const emoticons= [1300, 1500, 1600, 4900];

    let insdCount =0;
    let buyPayment = 0;
    for (user of users){
        let payment = 0;
        const userLikeRate = user[0];
        const userThreadsHold = user[1];

        for (let i =0; i<emoticons.length; i++){
            if (userLikeRate > state[i] ) continue;
            const bill = emoticons[i]*(100-state[i])/100
            payment += bill;
        }

        console.log(user, userLikeRate, userThreadsHold, payment)
        if (payment >= userThreadsHold) {
            insdCount++;
        } 
        else buyPayment += payment;
    }
    console.log(insdCount, buyPayment);
}

test(
    [ [40, 10000], [25, 10000], ], 
    [7000, 9000] ,
    [25, 40]
);
    

test( 
    [ [40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900] ], 
    [1300, 1500, 1600, 4900],
    [40 , 40, 20, 40]
);
