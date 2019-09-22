using Newtonsoft.Json;
using System.Collections.Generic;

namespace offlineTest.Model
{
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
