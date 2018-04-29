//
// Created by lango on 4/30/18.
//
#include <<filesystem/VolumeManager.cpp>
#include <filesystem/File.h>

VolumeManager::VolumeManager(FileSystem *fs)
{
    this->fs = *fs;
}

VolumeManager::~VolumeManager()
{
}

File* VolumeManager::openFile(const char* _filename)
{
    if(filename)
    {
        //default is sdA -- /dev/sda
        unsigned char defaultDevice = 'a';
        char* filename = _filename;

        //File is stored as /dev/sda/file or /dev/sda/directory/file etc..
        if(filename[1] == '/')
        {
            filename += 2; //Strip device from
        }

        if(this->fs[device - defaultDevice])
        {
            File* file = this->fs[device - defaultDevice]->open(filename);
            return file;
        }

        File* file;
        file->setFlag(FS_INVALID);
        return file;
    }
}