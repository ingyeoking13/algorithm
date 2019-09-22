using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Headers;

namespace duplicatedForTest
{
    class Solver
    {
        private string URL = "https://wqwfrkh5k1.execute-api.ap-northeast-2.amazonaws.com/kakao-2020/";
        private string _token = "4df71c660a219ce18baee4c2bbc34546";
        HttpClient _client;
        private int paging = 1;
        int dates = 0;
        public Solver()
        {
            _client = new HttpClient();
            _client.BaseAddress = new Uri(URL);
            _client.DefaultRequestHeaders.Accept.Add(
                new MediaTypeWithQualityHeaderValue("application/json")
            );
            _client.DefaultRequestHeaders.Add("X-Auth-Token", _token);
        }

        public void GetAllMethod()
        {
            HttpResponseMessage response = _client.GetAsync("").Result;
            if (response.IsSuccessStatusCode)
            {
                var myobject = response.Content.ReadAsStringAsync().Result;
                JObject obj = JObject.Parse(myobject);
                Console.WriteLine(obj);
            }
        }

        public void BasicGet()
        {
            HttpResponseMessage response = _client.GetAsync("planets/1/").Result;

            if (response.IsSuccessStatusCode)
            {
                var myobject = response.Content.ReadAsStringAsync().Result;
                JObject obj = JObject.Parse(myobject);

                Console.WriteLine(obj["name"]);
            }
        }

        public (bool resBool, string msg) GetStart(int problemNumber)
        {
            var content = new StringContent($"{{\"problem\":{problemNumber}}}");
            HttpResponseMessage response = _client.PostAsync("start", content).Result;

            if (response.IsSuccessStatusCode)
            {
                var myOjbect = response.Content.ReadAsStringAsync().Result;
                JObject obj = JObject.Parse(myOjbect);
                string auth_token = obj["token"].ToString();
                Console.WriteLine(obj);
                _client.DefaultRequestHeaders.Add("Authorization", auth_token);
            }
            else return (false, "fail to get probToken");

            /// start 
            for (int days = 1; days <= 500; days++)
            {
                //querying  **users**
                string param = $"users/?page=1&size=3000";
                response = _client.GetAsync(param).Result;
                //end of querying

                if (!response.IsSuccessStatusCode) return (false, "get user content");

                var myObject = response.Content.ReadAsStringAsync().Result;
                JObject obj = JObject.Parse(myObject);

                var userQueryRes = JsonConvert.DeserializeObject<userQuery>(obj.ToString());
                // retrieve **users**

                int userId = 0;
                Dictionary<string, int> myHash = new Dictionary<string, int>();
                List<string> inverseMyHash = new List<string>();

                foreach (var i in userQueryRes.users)
                {
                    myHash.Add(i.myPhone, userId);
                    inverseMyHash.Add(i.myPhone);
                    userId++;
                }

                //팔로잉 여부 체크 
                SortedSet<(int, int)> isFollowing = new SortedSet<(int, int)>();

                //폰 가지고 있는지 여부 체크 
                SortedSet<(int, int)> havingPhoneNum = new SortedSet<(int, int)>();

                Dictionary<int, List<int>> beingPhoneNum = new Dictionary<int, List<int>>();
                Dictionary<int, List<int>> beingFollowed = new Dictionary<int, List<int>>();

                //추천 확률 계산 
                Dictionary<int, List<(double prob, int v)>> ProbSet = new Dictionary<int, List<(double prob, int v)>>();

                //모든 경우의 유저들에 대해 
                foreach (var i in userQueryRes.users)
                {
                    int myPhoneId = myHash[i.myPhone];

                    foreach (var other in i.following)
                    {
                        if (myHash.ContainsKey(other) == false)
                        {
                            myHash.Add(other, userId++);
                            inverseMyHash.Add(other);
                        }
                        int otherPhoneId = myHash[other];
                        isFollowing.Add((myPhoneId, otherPhoneId));

                        if (beingFollowed.ContainsKey(otherPhoneId))
                            beingFollowed[otherPhoneId].Add(myPhoneId);
                        else
                            beingFollowed.Add(otherPhoneId, new List<int> { myPhoneId });
                    }

                    foreach (var other in i.phone)
                    {
                        if (myHash.ContainsKey(other) == false)
                        {
                            myHash.Add(other, userId++);
                            inverseMyHash.Add(other);
                        }
                        int otherPhoneId = myHash[other];
                        havingPhoneNum.Add((myPhoneId, otherPhoneId));

                        if (beingPhoneNum.ContainsKey(otherPhoneId))
                            beingPhoneNum[otherPhoneId].Add(myPhoneId);
                        else
                            beingPhoneNum.Add(otherPhoneId, new List<int> { myPhoneId });
                    }
                }


                userQueryRes.users.Sort(
                    (x, y) => x.following.Count.CompareTo(y.following.Count)
                );
                userQueryRes.users.Reverse();

                int Added = 0;

                foreach (var user in userQueryRes.users)
                {
                    int myPhoneId = myHash[user.myPhone];
                    if (user.following.Count >= 20) continue;
                    //if (Added >= userQueryRes.total) break;

                    foreach (var other in userQueryRes.users)
                    {
                        if (user == other) continue;

                        int otherPhoneId = myHash[other.myPhone];
                        //이미 팔로잉하고 있으면 상관없음, 확률 계산 상관없음  
                        if (isFollowing.Contains((myPhoneId, otherPhoneId)) == true) continue;

                        Added++;

                        double prob = 0;

                        //내 전화번호부에 있는경우 
                        if (havingPhoneNum.Contains((myPhoneId, otherPhoneId))) prob += 30;
                        else prob += 5;

                        if (beingPhoneNum.ContainsKey(otherPhoneId))
                        {
                            foreach (var friendPhoneId in beingPhoneNum[otherPhoneId])
                            {
                                if (havingPhoneNum.Contains((myPhoneId, friendPhoneId)) == true) prob += 10;
                                if (isFollowing.Contains((myPhoneId, friendPhoneId)) == true) prob += 10;
                            }
                        }

                        if (ProbSet.ContainsKey(myPhoneId))
                            ProbSet[myPhoneId].Add((prob, otherPhoneId));
                        else
                            ProbSet.Add(myPhoneId, new List<(double, int)> { (prob, otherPhoneId) });
                    }
                }


                Dictionary<int, List<(int, double prob)>> TopTen = new Dictionary<int, List<(int, double prob)>>();
                foreach (var UserProb in ProbSet)
                {
                    var val = UserProb.Value;
                    val.Sort((x, y) => x.Item1.CompareTo(y.Item1));
                    val.Reverse();

                    List<(int, double)> topten = new List<(int, double)>();

                    //max 10 명 
                    for (int i = 0; i < Math.Min(10, val.Count); i++)
                    {
                        topten.Add((val[i].Item2, val[i].Item1));
                    }
                    TopTen.Add(UserProb.Key, topten);
                }

                List<(int u, int v, double prob)> totalProb = new List<(int u, int v, double prob)>();

                foreach (var UserProb in TopTen)
                {
                    foreach (var ttuple in UserProb.Value)
                    {
                        totalProb.Add((UserProb.Key, ttuple.Item1, ttuple.Item2));
                    }
                }

                totalProb.Sort((x, y) => x.Item3.CompareTo(y.Item3));
                totalProb.Reverse();

                Dictionary<string, List<string>> Answer = new Dictionary<string, List<string>>();

                for (int i = 0; i < Math.Min(userQueryRes.total, totalProb.Count); i++)
                {
                    string u = inverseMyHash[totalProb[i].u];
                    string v = inverseMyHash[totalProb[i].v];

                    if (Answer.ContainsKey(u))
                        Answer[u].Add(v);
                    else
                        Answer.Add(u, new List<string> { v });
                }

                Recommendations AnswerQuery = new Recommendations();
                foreach (var Ans in Answer)
                {
                    Recommendation recommend = new Recommendation();
                    recommend.user = Ans.Key;
                    recommend.recommendation = Ans.Value;
                    AnswerQuery.recommendations.Add(recommend);
                }

                if (AnswerQuery.recommendations.Count > 0)
                {


                    var recBodyContent = JsonConvert.SerializeObject(AnswerQuery);
                    Console.WriteLine(recBodyContent);
                    var Content = new StringContent(recBodyContent);

                    var rres = _client.PostAsync("recommend", Content).Result;

                    if (!rres.IsSuccessStatusCode) return (false, "operate recommend error");
                }
                else
                {
                    paging++;
                    paging = paging % 12;
                    if (paging == 0) paging = 12;
                }

                var res = _client.PutAsync("run_simulation", new StringContent("")).Result;
                if (!res.IsSuccessStatusCode) return (false, res.Content.ReadAsStringAsync().Result);


                while (true)
                {
                    res = _client.GetAsync("status").Result;
                    var statusObject = res.Content.ReadAsStringAsync().Result;
                    var resulllt = JObject.Parse(statusObject);
                    Console.WriteLine(resulllt["status"]);
                    if (resulllt["status"].ToString() == "done") break;
                    else if (resulllt["status"].ToString() == "finish")
                    {
                        return (true, _token);
                    }
                }

            }

            return (true, "good");
        }
    }
}