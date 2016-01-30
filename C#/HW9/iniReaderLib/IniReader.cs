using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace iniReaderLib
{
    public class IniReader
    {
        Dictionary<string, string> parameters = new Dictionary<string, string>();
        public string GetKeyValueStr(string sSection, string sKey, string sDefault)
        {
            foreach (KeyValuePair<string, string> kvp in parameters)
                if (kvp.Key == sKey)
                    return kvp.Value;
            return sDefault;
        }
        public int GetKeyValueInt(string sSection, string sKey, int iDefault)
        {
            foreach (KeyValuePair<string, string> kvp in parameters)
                if (kvp.Key == sKey)
                    return Int32.Parse(kvp.Value);
            return iDefault;
        }
        public bool GetKeyValueBool(string sSection, string sKey, bool bDefault)
        {
            foreach (KeyValuePair<string, string> kvp in parameters)
                if (kvp.Key == sKey)
                    return bool.Parse(kvp.Value);
            return bDefault;
        }

        public Dictionary<string, string> Read(string iniPath)
        {
            using (FileStream fs = new FileStream(iniPath, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
            {
                StreamReader reader = new StreamReader(fs);
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine();
                    Match cityAndNumber = Regex.Match(line, @"(\w+)\s*=\s*(\w+)");
                    if (cityAndNumber.Success)
                    {
                        GroupCollection groups = cityAndNumber.Groups;
                        string value = groups[2].Value;
                        string parameter = groups[1].Value;
                        parameters.Add(parameter, value);
                    }
                }
                return parameters;
            };
        }
    }
}
