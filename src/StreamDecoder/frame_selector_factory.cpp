//
// Projectname: amos-ss16-proj5
//
// Copyright (c) 2016 de.fau.cs.osr.amos2016.gruppe5
//
// This file is part of the AMOS Project 2016 @ FAU
// (Friedrich-Alexander University Erlangen-Nürnberg)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public
// License along with this program. If not, see
// <http://www.gnu.org/licenses/>.
//

#include "frame_selector_factory.h"
#include "hdf5_frame_selector.h"
#include "frame_selector.h"

FrameSelectorFactory::FrameSelectorFactory(std::string file){
    file_name_= file;
}

FrameSelector * FrameSelectorFactory::GetFrameSelector(){
    if (HasSuffix(file_name_, ".HDF5")||HasSuffix(file_name_, ".hdf5")){
        return new HDF5FrameSelector(file_name_);
    }
    else return NULL;
}


bool FrameSelectorFactory::HasSuffix(const std::string &filename,const std::string &suffix){
    return filename.compare(filename.size() - suffix.size(), suffix.size(), suffix) == 0;
}