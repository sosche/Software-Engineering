//@(#) DeviceVerwalter.h

#ifndef DEVICEVERWALTER_H_H
#define DEVICEVERWALTER_H_H

#include <string>
#include <map>

#include "InternalDevice.h"
#include "VorhandeneZutaten.h"
#include "Dosierer.h"
#include "Mixer.h"
#include "Stampfer.h"
#include "Schuettler.h"
#include "Entleerer.h"
#include "Waage.h"

/**
 * @class DeviceVerwalter
 *
 * @brief DeviceVerwalter fills the Dosierer and manages the intern hardware
 * It sets up all the hardware that is used and fills the Dosierer with the matching ingredients
 *  
 */
class DeviceVerwalter {
public:
    /**
     * @brief Constructor makes a DeviceVerwalter using a pointer of VorhandeneZutaten
     *
     * it calls the setZutatenVerwalter method and the createDevices method
     * @param ze is a pointer of the VorhandeneZutaten class
     */
    explicit DeviceVerwalter(VorhandeneZutaten * ze);

    /**
     * @brief the method sets up myDevices and passes the ingredient and number to it
     *
     * it decides weather it takes pieces of zutat or the weight of zutat
     * @param zutat is the ingredient of the making step
     * @param menge is how much of zutat is used
     */
    std::vector<InternalDevice*> rezeptSchrittZubereiten(std::string zutat, float menge);

    /**
     * @brief returns a Dosierer
     * @param zutat
     * @return Dosierer
     */
    std::vector<InternalDevice*> getDevices(std::string zutat);
    /**
     * @brief it sets the doIt method of the myEntleerer device
     * @param menge is the amount that is set in the doit method of myEntleerer
     */

    void entleeren(float menge);

    /**
     * @brief shows the device that is cleaning at the moment
     */
    void putzen();

private:
    /**
     * @brief sets up myZutatenVerwalter
     * @param ze is a pointer of VorhandeneZutaten class
     */
    void setZutatenVerwalter(VorhandeneZutaten * ze);

    /**
     * @brief is a map of InternalDevices with the according name
     *
     */
    std::multimap<std::string, InternalDevice *> * myDevices;

    /**
     * @brief is a pointer of Entleerer class
     * it is used by the entleeren method
     */
    Entleerer * myEntleerer;
    /**
     * @brief is a pointer of Mixer class
     * it is used for mixing the ingredients
     */
    Mixer * myMixer;

    /**
     * @brief is a pointer of Stampfer class
     * it is used for pressing the ingredients
     */
    Stampfer * myStampfer;
    /**
     * @brief is a pointer of Schuettler class
     * it is used to shake the ingredients
     */

    Schuettler * mySchuettler;
    /**
       * @brief is a pointer of VorhandeneZutaten class
       * it is used tell the method it is called by the used ingredient for the recipe step
       */
    VorhandeneZutaten * myZutatenVerwalter;

    /**
     * @brief is a pointer of Waage class
     * it is used for how much weight is desired of an ingredient
     */
    Waage * theWaage;
    /**
     * @brief sets up all used Devices
     * it sets up the Devices and tells myZutatenVerwalter if the the Dosierer should use the weight or the pieces of an
     * ingredient
     */
    void createDevices();

};

#endif
