# OG Global Roles

## Notes

- Works **only** for groups using the `og_roles_permissions` field.

## Test Cases

### Create new group with default OG permissions

**Steps:**

1. Create new group with "Use default roles and permissions" selected for the
"Group roles and permissions" field.

**Desired result:**

- Global roles are created for all default OG roles for this group with naming
pattern "[group entity type]:[group entity id]:[og role id]:[og role name]"
    - NOTE: This may be truncated, as the role name cannot exceed 64 characters
    in length, this is why we maintain the table below
- New entries are created in the "og_global_role_map" table mapping og role ids
(with group ids) to global role ids

### Create new group with custom OG permissions

**Steps:**

1. Create new group with "Override default roles and permissions" selected for
the "Group roles and permissions" field.

**Desired result:**

- Global roles are created for all new OG roles for this group with naming
pattern "[group entity type]:[group entity id]:[og role id]:[og role name]"
    - NOTE: This may be truncated, as the role name cannot exceed 64 characters
    in length, this is why we maintain the table below
- New entries are created in the "og_global_role_map" table mapping og role ids
(with group ids) to global role ids

### Update existing group, switching from "default" permissions to "overridden"

**Steps:**

1. Edit an existing group that uses "default" og permissions.
2. Change "Group roles and permssions" field to "Override default roles and
permissions".
3. Save the group.

**Desired result:**

- Global roles for "default" og roles with this group are deleted.
    - Old entries in global map table are removed.
- New global roles for new og roles with this group are added.
    - New entries in global map table are added.

### Update existing group, switching from "overridden" permissions to "default"

**Steps:**

1. Edit an existing group that uses "overridden" og permissions.
2. Change "Group roles and permssions" field to "Use default roles and
permissions".
3. Save the group.

**Desired result:**

- Global roles for "overridden" og roles with this group are deleted.
    - Old entries in global map table are removed.
- New global roles for default og roles with this group are added.
    - New entries in global map table are added.
