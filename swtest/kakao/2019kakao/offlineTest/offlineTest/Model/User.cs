using Newtonsoft.Json;
using System.Collections.Generic;

namespace offlineTest.Model
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
}
