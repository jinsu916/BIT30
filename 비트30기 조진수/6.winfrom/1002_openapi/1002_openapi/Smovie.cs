using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _1002_openapi
{
    class Smovie
    {
        public string Title { get; private set; }
        public string Link { get; private set; }
        public string Image { get; private set; }
        public string Subtitle { get; private set; }
        public string PubDate { get; private set; }
        public string Director { get; private set; }
        public string Actor { get; private set; }
        public float UserRating { get; private set; }

        static public Smovie MakeMovie(XmlNode xr)
        {
            string title = string.Empty;
            string link = string.Empty;
            string image = string.Empty;
            string subtitle = string.Empty;
            string pubDate = string.Empty;
            string director = string.Empty;
            string actor = string.Empty;
            float userRating = 0.0f;

            XmlNode title_node = xr.SelectSingleNode("title");
            title = ConvertString(title_node.InnerText);

            XmlNode link_node = xr.SelectSingleNode("link");
            link = ConvertString(link_node.InnerText);

            XmlNode image_node = xr.SelectSingleNode("image");
            image = ConvertString(image_node.InnerText);

            XmlNode subtitle_node = xr.SelectSingleNode("subtitle");
            subtitle = ConvertString(subtitle_node.InnerText);

            XmlNode pubdate_node = xr.SelectSingleNode("pubDate");
            pubDate = ConvertString(pubdate_node.InnerText);

            XmlNode director_node = xr.SelectSingleNode("director");
            director = ConvertString(director_node.InnerText);

            XmlNode actor_node = xr.SelectSingleNode("actor");
            actor = ConvertString(actor_node.InnerText);

            XmlNode userrating_node = xr.SelectSingleNode("userRating");
            userRating = float.Parse(ConvertString(userrating_node.InnerText));

            return new Smovie(title, link, image, subtitle, pubDate, director, actor, userRating);
        }

        static private string ConvertString(string str)
        {
            return str;
        }

        public Smovie(string t, string l, string i, string s, string p, string d, string a, float u)
        {
            Title = t;
            Link = l;
            Image = i;
            Subtitle = s;
            PubDate = p;
            Director = d;
            Actor =  a;
            UserRating = u;
        }
    }
}
