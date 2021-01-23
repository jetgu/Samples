There are 3 samples for Silk CGI:
(1) env.si - list CGI enviroment values.
(2) fileserver.si - a http file server which supports folder file listing, download and file upload.
(3) run.si - run Silk code

////////////////////////////////////////////////////////
How to run  the sample of Silk CGI in Windows:
1. Download Windows Apache at https://www.apachehaus.com/cgi-bin/download.plx
2. Extract it into a directory, we suppose you extract it in c:\apache2
3. Edit the httpd.conf file in c:\apache2\conf for the following sections:
ScriptAlias /cgi-bin/ "c:/apache2/cgi-bin/"

<Directory "c:/apache2/cgi-bin">
AllowOverride None
Options ExecCGI
Order allow,deny
Allow from all
</Directory>

AddHandler cgi-script .exe .pl .cgi .si

4. Copy all Silk script files(fileserver.si, cgi.si...) and the dll file(SilkCommonLib64.dll) into the CGI directory c:/apache2/cgi-bin
5. Click the httpd.exe in c:/apache2/bin to start Apache
6. Test the cgi:
open the URL in browser:
http://192.168.0.100/cgi-bin/env.si
http://192.168.0.100/cgi-bin/fileserver.si
http://192.168.0.100/cgi-bin/run.si

We suppose you run the Apache server on the IP address 192.168.0.100

////////////////////////////////////////////////////////
How to run  the sample of Silk CGI in Linux:
1. Install and start Apache in Linux, here is the example in Ubuntu:
sudo apt-get update
sudo apt-get install apache2
sudo /etc/init.d/apache2 start

2. Enable CGI
sudo ln -s /etc/apache2/mods-available/cgid.conf /etc/apache2/mods-enabled/cgid.conf
sudo ln -s /etc/apache2/mods-available/cgid.load /etc/apache2/mods-enabled/cgid.load
sudo ln -s /etc/apache2/mods-available/cgi.load /etc/apache2/mods-enabled/cgi.load

3. Edit the first line of the Silk script file env.si to tell Apache the location of the Silk interpreter file:
#!/mnt/d/silklang/silk

We suppose that you put Silk executable file in /mnt/d/silklang

4. Copy Silk script files and the dll file into CGI directory:
cp *.si  /usr/lib/cgi-bin
cp SilkCommonLib /usr/lib/cgi-bin

Note: if you get the error 'Load lib error' when you run the CGI file fileserver.si, you may need to compile the dll file SilkCommonLib with the source code again.

5. Restart apache:
sudo /etc/init.d/apache2 restart

6. Test the cgi:
open the URL in browser:
http://192.168.0.100/cgi-bin/env.si
http://192.168.0.100/cgi-bin/fileserver.si
http://192.168.0.100/cgi-bin/run.si

We suppose you run the Apache server on the IP address 192.168.0.100