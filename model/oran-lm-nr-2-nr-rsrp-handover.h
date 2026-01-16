#ifndef ORAN_LM_NR_2_NR_RSRP_HANDOVER_H
#define ORAN_LM_NR_2_NR_RSRP_HANDOVER_H

#include "oran-lm.h"

#include "ns3/log.h"
#include "ns3/vector.h"

namespace ns3
{
/**
 * @ingroup oran
 *
 * Logic Module for the Near-RT RIC that issues Commands to handover from
 * an NR cell to another based on RSRP from the UE to the gNBs.
 */
class OranLmNr2NrRsrpHandover : public OranLm
{
  protected:
    /**
     * UE related information
     */
    struct UeInfo
    {
        uint64_t nodeId; //!< The Node ID.
        uint16_t cellId; //!< The Cell ID.
        uint16_t rnti;   //!< The RNTI ID.
        Vector position; //!< The position of the UE.
    };

    /**
     * Cell related information
     */
    struct gNBInfo
    {
        uint64_t nodeId; //!< The Node ID.
        uint16_t cellId; //!< The Cell ID.
        Vector position; //!< The position of the gNB.
    };

  public:
    /**
     * Gets the TypeId of the OranLmNr2NrRsrpHandover class.
     *
     * @returns The TypeId.
     */
    static TypeId getTypeId(void);
    /**
     * The constructor for the OranLmNr2NrRsrpHandover class.
     */
    OranLmNr2NrRsrpHandover(void);
    /**
     * The destructor for the OranLmNr2NrRsrpHandover class.
     */
    ~OranLmNr2NrRsrpHandover(void) override;
    /**
     * Runs the logic specific to this LM.
     * This LM in particular retrieves all UEs, finds the gNB with the greatest RSRP to each UE,
     * and if this gNB is not already serving the UE, issue a handover request to the gNB.
     *
     * @returns A vector of handover commands generated.
     */
    std::vector<Ptr<OranCommand>> OranLmNr2NrRsrpHandover::Run(void) override;
};
} // namespace ns3

#endif /* ORAN_LM_NR_2_NR_RSRP_HANDOVER_H */