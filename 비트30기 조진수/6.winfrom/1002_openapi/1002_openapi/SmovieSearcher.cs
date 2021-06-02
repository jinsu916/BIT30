using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _1002_openapi
{
    class SmovieSearcher
    {
        XmlDocument doc;
        public List<Smovie> movielist = new List<Smovie>();
        public string MovieName { get; private set; }
        public string XmlString { get; private set; }

        public void SearchMovie(string str)
        {
            movielist.Clear(); //기존에 있던거 삭제해야함
            XmlString = Find(str);
            doc = new XmlDocument();
            doc.LoadXml(XmlString);
            // doc.Save("sss.xml");
            XmlNode node = doc.SelectSingleNode("rss");
            XmlNode n = node.SelectSingleNode("channel");
            Smovie smovie = null;
            foreach (XmlNode el in n.SelectNodes("item"))
            {
                smovie = Smovie.MakeMovie(el);
                movielist.Add(smovie);
            }
        }

        public string Find(string str)
        {
            string query = str; // 검색할 문자열
            //string url = "https://openapi.naver.com/v1/search/image?query=" + query; // 결과가 JSON 포맷
            string url = "https://openapi.naver.com/v1/search/movie.xml?query=" + query;  // 결과가 XML 포맷
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
            request.Headers.Add("X-Naver-Client-Id", "iDIVfmHmvLrFSXiLqgv0"); // 클라이언트 아이디
            request.Headers.Add("X-Naver-Client-Secret", "4PjDBLhn3N");       // 클라이언트 시크릿
            HttpWebResponse response = (HttpWebResponse)request.GetResponse();
            string status = response.StatusCode.ToString();
            if (status == "OK")
            {
                Stream stream = response.GetResponseStream();
                StreamReader reader = new StreamReader(stream, Encoding.UTF8);
                string text = reader.ReadToEnd();
                return text;
            }
            else
            {
                return string.Format("Error 발생= " + status);
            }
        }
    }
}
