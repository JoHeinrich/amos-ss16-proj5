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

//std
#include <string>


//local
#include "../StreamDecoder/frame_selector.h"
#include "../StreamDecoder/frame_selector_factory.h"
#include "../StreamDecoder/image.h"
#include "../CarCommunication/protoagent.h"

class Controller{

public:
    /**
     * Opens a HDF5 videofile and displays it
     *
     * @param videofile path to the video file
     */
    void PlayAsVideo(std::string videofile);
    
    /**
     * Opens a HDF5 videofile, calls the Detectors, Analyser and displays the video and the Analyser results
     *
     * @param videofile The path to the video file
     *
     */
    void AnalyseVideo(std::string videofile);

    /**
     * Saves all images as jepg to disc space
     *
     *@param videofile The path to the video file
     */
    void SaveAllImagesAsJPEG(std::string videofile);
    
    /**
     *
     * Initalizes the connection to another car
     *
     * @param port The port for the communication module (default = 0)
     * @param host The host for the communication module (default = "")
     */
    void InitilalizeCarConnection(uint16_t port, std::string host);
    
private:
    
    /**
     *
     * Notifies the other car wirh a given scenario
     *
     * @param scenario The scenario that should be sent
     */
    void NotifyOtherCar (Scenarios scenario);
    
    ProtoAgent * agent_;//The agent for the communication
    bool communication_is_activated_=false;//flag, if the communication is activated
};
