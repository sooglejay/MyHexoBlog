
---
title: Apache Configure To Solve 403
---
 
Recently, we came across an error - "Forbidden You don't have permission to access / on this server" while trying to run a new virtual host on our Ubuntu 14.04 machine. The first step to troubleshoot this type of issue would be to check at your Apache error logs as this specific type status can be thrown due to many reasons.

Since we have Apache 2.4.7 installed on our system, each virtual host file should have the .conf extension. We corrected the extension also. But the issue was still there. However this information lead us to think on it further and finally we found the reason for the issue.


The access control configuration has changed in the newer version of Apache and many of the old configurations are deprecated in Apache 2.4. The old configuration 'Allow from all' is no more compatible and 'Require all granted' is the new equivalent.


Here are some examples for Apache 2.2 Vs Apache 2.4 access controls.

Apache 2.2 config:

    Order allow,deny
    Allow from all


Apache 2.4 config:

    Require all granted

For fixing the above issue, just replace

    Order allow,deny 
    Allow from all

with

    Require all granted
in your new virtual host .conf file. Hope this helps. 