using Newtonsoft.Json;
using System.Collections.Generic;

namespace offlineTest.Model
{
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
}
