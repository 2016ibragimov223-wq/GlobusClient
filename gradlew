#!/usr/bin/env sh
APP_BASE_NAME=`basename "$0"`
SAVED="`pwd`"
cd "`dirname \"$0\"`" >/dev/null
APP_HOME="`pwd -P`"
cd "$SAVED"
CLASSPATH=$APP_HOME/gradle/wrapper/gradle-wrapper.jar
exec java -classpath "$CLASSPATH" org.gradle.wrapper.GradleWrapperMain "$@"
