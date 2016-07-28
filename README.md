NewtHTTPd version 0.0.0(prealpha) on July2016

NewtHTTPd is a simple, small, portable, fast, and secure HTTP server based on thttpd 2.27.

Simple: It handles only the minimum necessary to implement HTTP/1.1.

Small: It has a very small run-time size, since it does not fork and is very careful about memory allocation.

Portable: Targeting POSIX systems: modern GNU/Linux, macOS, and FreeBSD

Fast: In typical use it's about as fast as the best full-featured servers
(Apache, NCSA, Netscape).  Under extreme load it's much faster.

Secure: It goes to great lengths to protect the web server machine
against attacks and breakins from other sites.

It also has one extremely useful feature (URL-traffic-based throttling) that
no other server currently has.

See the manual entry for more details.  See the INSTALL file for
configuration and installation instructions.  Check the web page
(https://github.com/Property404/newthttpd) for updates.

Comments to:
	Dagan Martinez		https://github.com/Property404
