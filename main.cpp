#include "WorkGroup.h"
#include "WorkIterator.h"
#include "FireEngineUnit.h"
#include "AmbulanceUnit.h"
#include "RescueTeamUnit.h"
#include "HazmatCertificationDecorator.h"
#include "MedicalSupportDecorator.h"
#include <iostream>
#include <string>

static void section(const std::string& label) {
    std::cout << "\n----- " << label << " -----\n";
}

int main() {
    // Build a 4-level hierarchy below the client boundary:
    // Incident -> Branch -> Division -> Strike Team -> Unit
    WorkGroup* incident = new WorkGroup("Incident 47 - Warehouse Fire");

    WorkGroup* opsBranch = new WorkGroup("Operations Branch");
    WorkGroup* medBranch = new WorkGroup("Medical Branch");
    WorkGroup* divisionA = new WorkGroup("Division A");
    WorkGroup* strikeTeam1 = new WorkGroup("Strike Team 1");

    FireEngineUnit* engine21 = new FireEngineUnit("Engine 21", 4);
    FireEngineUnit* engine22 = new FireEngineUnit("Engine 22", 4);
    RescueTeamUnit* rescue5 = new RescueTeamUnit("Rescue 5", 3);
    AmbulanceUnit* ambulance9 = new AmbulanceUnit("Ambulance 9", 2);

    strikeTeam1->add(engine21);
    strikeTeam1->add(engine22);
    divisionA->add(strikeTeam1);
    divisionA->add(rescue5);
    opsBranch->add(divisionA);
    medBranch->add(ambulance9);
    incident->add(opsBranch);
    incident->add(medBranch);

    // ---- Traversal without exposing internals: complete roll call ----
    section("Roll call (DepthFirstIterator - complete traversal)");
    WorkIterator* rollCall = incident->createDepthFirstIterator();
    while (rollCall->hasNext()) {
        std::cout << rollCall->next()->getName() << "\n";
    }
    delete rollCall;

    // ---- State-dependent behaviour: valid transitions, then an invalid one ----
    section("Lifecycle: Engine 21 responds");
    engine21->dispatch();
    engine21->enRoute();
    engine21->arrive();
    engine21->dispatch(); // invalid: already OnScene, rejected and logged, no crash

    // ---- Two independent traversals of the same structure, in flight together ----
    section("Two independent iterators over the same hierarchy");
    WorkIterator* availableWalk = incident->createAvailableUnitIterator();
    // WorkIterator* fullWalk = incident->createDepthFirstIterator();
    
    // // Test delete after iterator snapshot
    // delete opsBranch;
    
    // std::cout << "Full roll call, first 3 entries, unaffected by the above:\n";
    // for (int i = 0; i < 3 && fullWalk->hasNext(); ++i) {
    //     std::cout << "  " << fullWalk->next()->getName() << "\n";
    // }
    // delete fullWalk;
    section("Iterator invalidation test");
    WorkIterator* fullWalk = incident->createDepthFirstIterator();
    delete opsBranch;
    std::cout << "Continuing traversal after deletion:\n";
    while (fullWalk->hasNext()) {
        std::cout << fullWalk->next()->getName() << "\n";
    }
    delete fullWalk;
    std::cout << "Units currently available:\n";
    while (availableWalk->hasNext()) {
        std::cout << "  " << availableWalk->next()->getName() << "\n";
    }
    delete availableWalk;

    // ---- Runtime structural + decoration change on a unit already in the hierarchy ----
    section("Dynamic decoration: Engine 22 gets hazmat + medical support");
    strikeTeam1->remove(engine22);
    WorkElement* decoratedEngine22 =
        new HazmatCertificationDecorator(new MedicalSupportDecorator(engine22));
    strikeTeam1->add(decoratedEngine22);
    std::cout << decoratedEngine22->getName() << " now carries "
              << decoratedEngine22->getPersonnelCount() << " personnel.\n";
    decoratedEngine22->performDuty();

    // ---- Runtime structural change: move a unit between groups ----
    section("Re-tasking: Rescue 5 moves from Division A into Strike Team 1");
    rescue5->dispatch();


    section("Full duty performance after all changes");
    incident->performDuty();

    section("Shutdown");
    delete incident; // recursively destroys every owned WorkElement, including the decorator chain
    std::cout << "Incident structure torn down cleanly.\n";

    return 0;
}
