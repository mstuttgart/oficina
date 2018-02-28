##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=GameBoyEmu
ConfigurationName      :=Release
WorkspacePath          := "/home/michell/Documents/Documentos/IDEs/Codelite/My Projects"
ProjectPath            := "/home/michell/Documents/Documentos/Desenvolvimento/GameBoyEmu"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Michell Stuttgart
Date                   :=12/29/14
CodeLitePath           :="/home/michell/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="GameBoyEmu.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS := -std=c++0x -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/game_boy_cpu.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_audio.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_mouse_manager.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/michell/Documents/Documentos/Desenvolvimento/GameBoyEmu/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/game_boy_cpu.cpp$(ObjectSuffix): game_boy_cpu.cpp $(IntermediateDirectory)/game_boy_cpu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/michell/Documents/Documentos/Desenvolvimento/GameBoyEmu/game_boy_cpu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/game_boy_cpu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/game_boy_cpu.cpp$(DependSuffix): game_boy_cpu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/game_boy_cpu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/game_boy_cpu.cpp$(DependSuffix) -MM "game_boy_cpu.cpp"

$(IntermediateDirectory)/game_boy_cpu.cpp$(PreprocessSuffix): game_boy_cpu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/game_boy_cpu.cpp$(PreprocessSuffix) "game_boy_cpu.cpp"

$(IntermediateDirectory)/ludic_audio.cpp$(ObjectSuffix): ../Ludic-Game-Library/src/ludic/audio.cpp $(IntermediateDirectory)/ludic_audio.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/michell/Documents/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/audio.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_audio.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_audio.cpp$(DependSuffix): ../Ludic-Game-Library/src/ludic/audio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_audio.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_audio.cpp$(DependSuffix) -MM "../Ludic-Game-Library/src/ludic/audio.cpp"

$(IntermediateDirectory)/ludic_audio.cpp$(PreprocessSuffix): ../Ludic-Game-Library/src/ludic/audio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_audio.cpp$(PreprocessSuffix) "../Ludic-Game-Library/src/ludic/audio.cpp"

$(IntermediateDirectory)/ludic_mouse_manager.cpp$(ObjectSuffix): ../Ludic-Game-Library/src/ludic/mouse_manager.cpp $(IntermediateDirectory)/ludic_mouse_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/michell/Documents/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/mouse_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_mouse_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_mouse_manager.cpp$(DependSuffix): ../Ludic-Game-Library/src/ludic/mouse_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_mouse_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_mouse_manager.cpp$(DependSuffix) -MM "../Ludic-Game-Library/src/ludic/mouse_manager.cpp"

$(IntermediateDirectory)/ludic_mouse_manager.cpp$(PreprocessSuffix): ../Ludic-Game-Library/src/ludic/mouse_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_mouse_manager.cpp$(PreprocessSuffix) "../Ludic-Game-Library/src/ludic/mouse_manager.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Release/*$(ObjectSuffix)
	$(RM) ./Release/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../../IDEs/Codelite/My Projects/.build-release/GameBoyEmu"


