import sys
import urllib as url

querry=sys.argv[0]
link='https://en.wikipedia.org/w/index.php?search='+querry+'&title=Special%3ASearch&go=Go&ns0=1'
s=url.urlopen(link)
f=s.read()
fi=open('C:/Users/Saurabh%20Roy/Desktop/lol.html','w')
fi.write(f)
fi.close()
