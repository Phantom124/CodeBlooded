#!/bin/bash

# Fix factory constructor calls - remove queryBuilder parameter
for file in test_factory_pattern.cpp test_state_pattern.cpp test_decorator_pattern.cpp test_command_pattern.cpp test_chain_of_responsibility.cpp test_memento_pattern.cpp test_composite_pattern.cpp test_builder_pattern.cpp; do
    if [ -f "$file" ]; then
        sed -i 's/RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder)/RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor)/g' "$file"
        sed -i 's/CactusFactory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder)/CactusFactory(waterMonitor, fertilizerMonitor, deadMonitor)/g' "$file"
        sed -i 's/SunflowerFactory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder)/SunflowerFactory(waterMonitor, fertilizerMonitor, deadMonitor)/g' "$file"
        sed -i 's/factory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder)/factory(waterMonitor, fertilizerMonitor, deadMonitor)/g' "$file"
        echo "Fixed $file"
    fi
done
