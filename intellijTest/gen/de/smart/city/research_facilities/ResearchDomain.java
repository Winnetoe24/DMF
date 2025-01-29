package de.smart.city.research_facilities;

/**
 * Detailed categorization enums
 **/
public enum ResearchDomain {
    QUANTUM_PHYSICS("Quantum Mechanics", 5),
    MOLECULAR_BIOLOGY("Molecular Studies", 4),
    NEUROSCIENCE("Brain Research", 5),
    CLIMATE_SCIENCE("Climate Studies", 4),
    MATERIALS_SCIENCE("Materials Research", 3),
    COMPUTER_SCIENCE("Computing", 4),
    PSYCHOLOGY("Behavioral Studies", 3),
    GENETICS("Genetic Research", 5),
    ROBOTICS("Robotics Research", 4),
    NANOTECHNOLOGY("Nano Research", 5);

    protected String field;
    protected int complexityLevel;

    ResearchDomain(String field, int complexityLevel){
        
        this.field = field;
        this.complexityLevel = complexityLevel;
    }
}