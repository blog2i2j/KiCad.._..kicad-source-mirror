/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2024 Mark Roszko <mark.roszko@gmail.com>
 * Copyright The KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <jobs/jobs_output.h>

class KICOMMON_API JOBS_OUTPUT_ARCHIVE : public JOBS_OUTPUT_HANDLER
{
public:
    JOBS_OUTPUT_ARCHIVE();

    enum class FORMAT
    {
        ZIP
    };

    bool HandleOutputs( const wxString& aBaseTempPath,
                        PROJECT* aProject,
                        const std::vector<JOB_OUTPUT>& aOutputsToHandle ) override;
    bool OutputPrecheck() override;

    void FromJson( const nlohmann::json& j ) override;
    void ToJson( nlohmann::json& j ) const override;

    FORMAT GetFormat() const { return m_format; }
    void SetFormat( FORMAT format ) { m_format = format; }

    wxString GetDefaultDescription() const override;

private:
    FORMAT m_format;
};