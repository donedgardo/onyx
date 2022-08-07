pipeline {
    agent any
    
    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                bat "\"C:/Users/ssjva/Documents/UnrealEngine/Engine/Binaries/DotNet/UnrealBuildTool/UnrealBuildTool.exe\" -projectfiles -project=\"%WORKSPACE%/onyx.uproject\" -game -rocket -progress"
                bat "\"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe\" \"%WORKSPACE%/onyx.sln\" /t:build /p:Configuration=\"Development Client\";Platform=Win64;verbosity=diagnostic" 
                bat "\"D:/UnrealEngine/Engine/Build/BatchFiles/RunUAT.bat\" BuildCookRun -rocket -compile -compileeditor -installed -nop4 -project=\"%WORKSPACE%/onyx.uproject\" -cook -stage -archive -archivedirectory=\"%WORKSPACE%/temp/Development/x64\" -package -clientconfig=Development -ue4exe=UnrealEditor-Cmd.exe -clean -pak -prereqs -distribution -nodebuginfo -targetplatform=Win64 -build -utf8output"
                bat "ren .\\temp\\Development\\x64\\Windows %BUILD_TAG%_Onyx_x64"
                bat "\"D:/7-Zip/7z.exe\" a -t7z builds/Development/%BUILD_TAG%_Onyx/%BUILD_TAG%_Onyx.rar \"%WORKSPACE%/temp/development/x64/%BUILD_TAG%_Onyx_x64\""
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
    post {
        success {
            archiveArtifacts artifacts: "builds/Development/${BUILD_TAG}_Onyx/*.rar", fingerprint: true
        }
    }
}