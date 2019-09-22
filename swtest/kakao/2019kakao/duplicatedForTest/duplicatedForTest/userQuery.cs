using Newtonsoft.Json;
using System.Collections.Generic;

namespace duplicatedForTest
{
    [JsonObject]
    class User
    {
        [JsonProperty("user")]
        public string myPhone { get; set; }
        [JsonProperty]
        public List<string> following { get; set; }
        [JsonProperty]
        public List<string> phone { get; set; }
    }
    [JsonObject]
    class userQuery
    {
        [JsonProperty]
        public int day { get; set; }
        [JsonProperty]
        public int page { get; set; }
        [JsonProperty]
        public int size { get; set; }
        [JsonProperty]
        public int total { get; set; }
        [JsonProperty]
        public List<User> users { get; set; }
    }
    [JsonObject]
    public class Recommendations
    {
        [JsonProperty]
        public List<Recommendation> recommendations { get; set; } = new List<Recommendation>();
    }

    [JsonObject]
    public class Recommendation
    {
        [JsonProperty]
        public string user { get; set; }
        [JsonProperty]
        public List<string> recommendation { get; set; } = new List<string>();
    }
}