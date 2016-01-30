using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MusicPlayer
{
    public class PlayListItem
    {
        public string FileName { get; }
        public string FullPath { get; }
        public PlayListItem(string filename, string fullPath) {
            FileName = filename;
            FullPath = fullPath;
        }

        public override string ToString() {
            return FileName;
        }
    }
}
