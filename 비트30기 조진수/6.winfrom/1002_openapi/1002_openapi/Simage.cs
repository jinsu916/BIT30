using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _1002_openapi
{
    class Simage
    {
        public string Title { get; private set; }
        public string Link { get; private set; }
        public string Thumbnail { get; private set; }
        public int SizeHeight { get; private set; }
        public int SizeWidth { get; private set; }

         static public Simage MakeImage(XmlNode xr)
        {
            string title = string.Empty;
            string link = string.Empty;
            string thumbnail = string.Empty;
            int sizeheight = 0;
            int sizewidth = 0;

            XmlNode title_node = xr.SelectSingleNode("title");
            title = ConvertString(title_node.InnerText);

            XmlNode link_node = xr.SelectSingleNode("link");
            link = ConvertString(link_node.InnerText);

            XmlNode thumbnail_node = xr.SelectSingleNode("thumbnail");
            thumbnail = ConvertString(thumbnail_node.InnerText);

            XmlNode sizeheight_node = xr.SelectSingleNode("sizeheight");
            sizeheight = int.Parse(ConvertString(sizeheight_node.InnerText));

            XmlNode sizewidth_node = xr.SelectSingleNode("sizewidth");
            sizewidth = int.Parse(ConvertString(sizewidth_node.InnerText));


            return new Simage(title, link, thumbnail, sizeheight, sizewidth);
        }
        static private string ConvertString(string str)
        {
            return str;
        }

        public Simage(string t, string l, string tu, int sh, int sw)
        {
            Title = t;
            Link = l;
            Thumbnail = tu;
            SizeHeight = sh;
            SizeWidth = sw;
        }
    }
}
