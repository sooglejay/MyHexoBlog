
drill-config.sh sets JAVA_HOME incorrectly for the Mac
----------------------------------

             Summary: drill-config.sh sets JAVA_HOME incorrectly for the Mac
                 Key: DRILL-4870
                 URL: https://issues.apache.org/jira/browse/DRILL-4870
             Project: Apache Drill
          Issue Type: Bug
    Affects Versions: 1.8.0
         Environment: MacOS with unset JAVA_HOME
            Reporter: Paul Rogers
            Assignee: Paul Rogers
            Priority: Minor
             Fix For: 1.9.0

 


It turns out that drill-config.sh is both improperly and unnecessarily setting 
the JAVA_HOME envrironment variable. That setting should be removed.

In the Drill 1.7 version, drill-config.sh checks if the JAVA_HOME environment 
variable is set. If not, it sets JAVA_HOME based on its guess as to the proper 
value.

In the 1.7 version, the veriable was set, but not exported, so the variable was 
never actually used.

The recent script fixes for 1.8 "fixed" the export problem. The fix works fine 
on Linux. But, the Java install on the Mac has a different structure than that 
on Linux. The value that drill-config.sh guesses is fine for Linux, wrong for 
the Mac.

When we export the (wrong) JAVA_HOME, Mac users who have not set JAVA_HOME will 
get the following error when using a Drill script:

./drill-embedded 
Unable to locate an executable at 
"/System/Library/Frameworks/JavaVM.framework/Versions/A/bin/java"

Mac users who do set JAVA_HOME will not encounter the problem (because 
drill-config.sh does not change an existing value.)

It seems likely that someone in the past ecountered the same problem and 
removed the export of DRILL_HOME as an attempt to fix the problem.

As it turns out, Java does know how to set JAVA_HOME properly if not set. So, 
setting JAVA_HOME is unnecessary.

The proper fix is to remove JAVA_HOME setting from drill-config.sh.

The workaround for any 1.8 user who encounters the problem is to edit their 
$DRILL_HOME/bin/drill-config.sh file and delete this line near the end of the 
file:

export JAVA_HOME



--
This message was sent by Atlassian JIRA
(v6.3.4#6332)
